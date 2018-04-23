/*		Author: Jimmy Griffiths & Walter Proulx
 *		Class : CSI-281-01
 *		Assignment : Final Project
 * 		Date Assigned : November 30, 2017
 * 		Due Date : November 5, 2017
 *
 *		Description :
 *			An implementation of the Apriori algorithm.
 *
 *		Certification of Authenticity :
 *			I certify that this is entirely my own work, except where I have given fully
 * 			documented references to the work of others. I understand the definition and
 * 			consequences of plagiarism and acknowledge that the assessor of this assignment
 * 			may, for the purpose of assessing this assignment :
 * 			-	Reproduce this assignment and provide a copy to another member of
 *				academic staff; and / or
 *			-	Communicate a copy of this assignment to a plagiarism checking service
 *				(which may then retain a copy of this assignment on its database for
 *				the purpose of future plagiarism checking)
 *
 ***********************************************************************************************/
#include "ItemsList.h"
#include "SubList.h"
#include "functions.h"

int main()
{
	/* declaring variables */
	int fileLength, itemCount, x, y;
	int supportMinimum = 2;
	string filename;
	SubList sub1, sub2;
	ItemsList items;
	int *itemTranslation;
	bool **transactions;
	bool arrayExists = true;
	bool subFlipper = true;			// value must be true
	ofstream fout("output.txt");
	
	/* retreiving filename and file length and item count  */
	filename = getFileName();
	fileLength = getItemList(filename, items);
	itemCount = items.getLength();

	/* initializing the item translation array */
	itemTranslation = new int[itemCount];
	transferItems(items, itemTranslation);

	/* initializing the transactions array */
	transactions = new bool*[fileLength];
	for (x = 0; x < fileLength; x++)
	{
		transactions[x] = new bool[itemCount];
	}
	for (x = 0; x < fileLength; x++)
	{
		for (y = 0; y < itemCount; y++)
		{
			transactions[x][y] = false;
		}
	}
	initializeTransactions(transactions, itemTranslation, itemCount, filename);

	/* generating subsets 1 & 2 */

	// make subset 1, calculate support, prune, and output
	generateSubSet1(sub1, itemCount);
	calculateSupport(sub1, sub2, true, transactions, fileLength, 1);
	pruneSubSet(sub1, sub2, true, 1, supportMinimum);
	outputSupport(sub1, sub2, true, fout, 1, itemTranslation);

	// make subset 2, calculate support, prune, and output
	generateSubSet2(sub1, sub2, itemCount);
	calculateSupport(sub1, sub2, false, transactions, fileLength, 2);
	pruneSubSet(sub1, sub2, false, 2, supportMinimum);
	outputSupport(sub1, sub2, false, fout, 2, itemTranslation);

	/* generating remaining subsets, calculate support, prune, and output */
	for (int i = 3; i < itemCount && arrayExists == true; i++)
	{
		generateSubSet(sub1, sub2, itemCount, i, subFlipper);
		calculateSupport(sub1, sub2, subFlipper, transactions, fileLength, i);
		pruneSubSet(sub1, sub2, subFlipper, i, supportMinimum);
		outputSupport(sub1, sub2, subFlipper, fout, i, itemTranslation);
		
		if (subFlipper)
		{
			arrayExists = !sub1.isEmpty();
		}
		else
		{
			arrayExists = !sub2.isEmpty();
		}

		subFlipper = !subFlipper;
	}

	/* deleting pointers */
	delete[] itemTranslation;
	for (x = 0; x < fileLength; x++)
	{
		delete[] transactions[x];
	}
	delete[] transactions;
	
	system("pause");
	return 0;
}