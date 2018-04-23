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
#include "functions.h"
#include "ItemsList.h"

/*      Pre:  SubList, SubList, bool, bool 2D array, int, int
 *     Post:  changes SubList objects
 *  Purpose:  goes through all the transactions and sees if a subset
 *			  appears in the transactions array, if they do then
 *			  increment the support
 ********************************************************************/
void calculateSupport(SubList& sub1, SubList& sub2, bool flipper, bool **transaction, int fileLength, int subsetLength)
{
	int i, j, k, subLength;
	bool isSupport;

	int *tempSubset;

	cout << "Calculating Support for Subset-" << subsetLength << endl;

	if (flipper == true)
	{
		subLength = sub1.getLength();

		for (i = 0; i < subLength; i++)
		{
			tempSubset = new int[subsetLength];

			for (j = 0; j < subsetLength; j++)
			{
				tempSubset[j] = sub1.getItem(i, j);
			}

			for (k = 0; k < fileLength; k++)
			{
				isSupport = true;

				for (j = 0; j < subsetLength; j++)
				{
					if (transaction[k][tempSubset[j]] == false)
					{
						isSupport = false;
					}
				}

				if (isSupport == true)
				{
					sub1.incrementSupport(i);
				}
			}

			delete[] tempSubset;
		}
	}
	else
	{
		subLength = sub2.getLength();

		for (i = 0; i < subLength; i++)
		{
			tempSubset = new int[subsetLength];

			for (j = 0; j < subsetLength; j++)
			{
				tempSubset[j] = sub2.getItem(i, j);
			}

			for (k = 0; k < fileLength; k++)
			{
				isSupport = true;

				for (j = 0; j < subsetLength; j++)
				{
					if (transaction[k][tempSubset[j]] == false)
					{
						isSupport = false;
					}
				}

				if (isSupport == true)
				{
					sub2.incrementSupport(i);
				}
			}

			delete[] tempSubset;
		}
	}
}

/*      Pre:  none
 *     Post:  string
 *  Purpose:  retrieves filename from user
 ********************************************************************/
string getFileName()
{
	string filename = "";

	fstream fin;

	while (filename == "")
	{
		cout << "Please enter a filename: ";

		getline(cin, filename);

		fin.open(filename);
		if (!fin.good())
		{
			cout << "ERROR: File not found!" << endl;
			filename = "";
			fin.close();
		}
	}

	fin.close();

	return filename;
}

/*      Pre:  string, ItemList
 *     Post:  int
 *  Purpose:  makes a list of all the objects in the file and stores
 *			  them in the ItemList object
 ********************************************************************/
int getItemList(string filename, ItemsList& items)
{
	int item;
	int fileLength = 0;
	fstream fin;
	string line;
	stringstream lineConvert;

	fin.open(filename);

	while (!fin.eof())
	{
		getline(fin, line);
		lineConvert << line;

		while (!lineConvert.eof())
		{
			lineConvert >> item;
			items.insert(item);
		}

		lineConvert.str("");
		lineConvert.clear();

		fileLength++;
	}

	fin.close();

	return fileLength;
}

/*      Pre:  SubList, int
 *     Post:  loads SubList object
 *  Purpose:  generate the 1-subsets of the transactions array
 ********************************************************************/
void generateSubSet1(SubList &sub1, int itemCount)
{
	//Knowing the transaction array is rows for transaction, columns for whether that thing exists in items or not...
	//read through and generate subsets of {1} {2}...{n} with support x
	//Is sublist an item or an index for the item?

	int i;
	int *sub1Index;
	for (i = 0; i < itemCount; i++)
	{
		sub1Index = new int[1];
		sub1Index[0] = i;
		sub1.insert(sub1Index, 1);
	}


}

/*      Pre:  SubList, SubList, int
 *     Post:  loads SubList object
 *  Purpose:  generate the 2-subsets of the transactions array
 ********************************************************************/
void generateSubSet2(SubList& sub1, SubList &sub2, int itemCount)
{
	//Knowing the transaction array is rows for transaction, columns for whether that thing exists in items or not...
	//read through and generate subsets of {1} {2}...{n} with support x
	//Is sublist an item or an index for the item?

	int i, j;
	int *sub2Index;
	for (i = 0; i < itemCount; i++)
	{
		for (j = i + 1; j < itemCount; j++)
		{
			sub2Index = new int[2];
			sub2Index[0] = i;
			sub2Index[1] = j;
			sub2.insert(sub2Index, 2);
		}
	}


}

/*      Pre:  SubList, SubList, int, int, bool 
 *     Post:  loads one SubList object
 *  Purpose:  generates the next subset based off the previous
 *			  SubList object
 ********************************************************************/
bool generateSubSet(SubList& sub1, SubList& sub2, int itemCount, int subSetNumber, bool subFlipper)
{
	int i, j, k, w;
	int *newSubSet;
	bool isSame = true;
	bool firstSame = true;

	if (subFlipper == true)
	{
		sub1.clear();

		for (i = 0; i < sub2.getLength(); i++)
		{
			firstSame = true;

			for (j = i + 1; j < sub2.getLength() && firstSame == true; j++)
			{
				isSame = true;
				
				for (k = 0; k < subSetNumber - 2 && isSame == true; k++)
				{
					if (sub2.getItem(i, k) != sub2.getItem(j, k))
					{
						isSame = false;
						if (k == 0)
						{
							firstSame = false;
						}
					}

				}

				if (isSame == true)
				{
					newSubSet = new int[subSetNumber];
					for (k = 0; k < subSetNumber - 1; k++)
					{
						newSubSet[k] = sub2.getItem(i, k);
					}
					newSubSet[subSetNumber - 1] = sub2.getItem(j, subSetNumber - 2);
					sub1.insert(newSubSet, subSetNumber);
					delete[] newSubSet;
				}
			}
		}

		return true;
	}
	else
	{
		sub2.clear();

		for (i = 0; i < sub1.getLength(); i++)
		{
			firstSame = true;

			for (j = i + 1; j < sub1.getLength() && firstSame == true; j++)
			{
				isSame = true;

				for (k = 0; k < subSetNumber - 2 && isSame == true; k++)
				{
					if (sub1.getItem(i, k) != sub1.getItem(j, k))
					{
						isSame = false;
						if (k == 0)
						{
							firstSame = false;
						}
					}
				}

				if (isSame == true)
				{
					newSubSet = new int[subSetNumber];
					for (k = 0; k < subSetNumber - 1; k++)
					{
						newSubSet[k] = sub1.getItem(i, k);
					}
					newSubSet[subSetNumber - 1] = sub1.getItem(j, subSetNumber - 2);
					sub2.insert(newSubSet, subSetNumber);
					delete[] newSubSet;
				}
			}
		}

		return true;
	}
}

/*      Pre:  2D dynamic bool array, string
 *     Post:  none
 *  Purpose:  goes through a transaction file and translates the file
 *			  from numbers to a 2D bool array
 ********************************************************************/
void initializeTransactions(bool **transaction, int* itemTranslation, int itemCount, string filename)
{
	int item;
	fstream fin;
	string line;
	stringstream lineConvert;

	fin.open(filename);

	for (int tranIndex = 0; !fin.eof(); tranIndex++)
	{
		getline(fin, line);
		lineConvert << line;

		while (!lineConvert.eof())
		{
			lineConvert >> item;
			item = searchItem(itemTranslation, item, itemCount);
			transaction[tranIndex][item] = 1;
		}

		lineConvert.str("");
		lineConvert.clear();
	}

	fin.close();
}

/*      Pre:  SubList, SubList, bool, ofstream, int
 *     Post:  none
 *  Purpose:  calls the output function with the correct SubList
 *			  object
 ********************************************************************/
void outputSupport(SubList& sub1, SubList& sub2, bool flipper, ofstream& fout, int subLength, int* itemTranslation)
{
	if (flipper)
	{
		sub1.outputToFile(subLength, fout, itemTranslation);
	}

	else
	{
		sub2.outputToFile(subLength, fout, itemTranslation);
	}
}

/*      Pre:  SubList, SubList, bool, int, int
 *     Post:  changes SubList
 *  Purpose:  goes through the SubList object and takes out all
 *			  subsets that do not meet the minimum support threshold
 ********************************************************************/
void pruneSubSet(SubList& sub1, SubList& sub2, bool subFlipper, int subsetLength, int supportMinimum)
{
	if (subFlipper == true)
	{
		for (int i = 0; i < sub1.getLength(); i++)
		{
			if (sub1.getSupport(i) < supportMinimum)
			{
				sub1.removeAt(i);
				i--;
			}
		}
	}
	else
	{
		for (int i = 0; i < sub2.getLength(); i++)
		{
			if (sub2.getSupport(i) < supportMinimum)
			{
				sub2.removeAt(i);
				i--;
			}
		}
	}
}


/*      Pre:  2D dynamic bool array, string
 *     Post:  none
 *  Purpose:  goes through a transaction file and translates the file
 *			  from numbers to a 2D bool array
 ********************************************************************/
int searchItem(int* itemTranslation, int item, int itemCount)
{
	int index;
	bool found = false;

	for (index = 0; index < itemCount && found == false; index++)
	{
		if (item == itemTranslation[index])
		{
			found = true;
			index--;
		}
	}

	return index;
}

/*      Pre:  ItemsList, int
 *     Post:  none
 *  Purpose:  transfers items from a ItemsList object to a dynamic
 *			  integer array
 ********************************************************************/
void transferItems(ItemsList& items, int* itemTranslation)
{
	int length = items.getLength();

	for (int x = 0; x < length; x++)
	{
		itemTranslation[x] = items.getItem(x);
	}
}