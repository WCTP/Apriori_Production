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
#ifndef SUB_LIST_H
#define SUB_LIST_H

#include <iostream>
#include <fstream>

using namespace std;

class SubList
{
	private:
		struct Node
		{
			int *mItemSubset;
			int mSupport;
			Node *mNext;

			/*      Pre:  none
			 *     Post:  initialize object
			 *  Purpose:  to initialize the data in the object
			 ********************************************************************/
			Node()
			{
				mItemSubset = NULL;
				mSupport = 0;
				mNext = NULL;
			}

			/*      Pre:  int dynamic array, int
			 *     Post:  initialize object
			 *  Purpose:  to initialize the data in the object
			 ********************************************************************/
			Node(int* itemSubset, int subsetLength)
			{
				mItemSubset = new int[subsetLength];
				for (int i = 0; i < subsetLength; i++)
				{
					mItemSubset[i] = itemSubset[i];
				}
				mSupport = 0;
				mNext = NULL;
			}

			/*      Pre:  int dynamic array, int
			 *     Post:  initialize object
			 *  Purpose:  to initialize the data in the object
			 ********************************************************************/
			~Node()
			{
				delete[] mItemSubset;
				mSupport = 0;
				mNext = NULL;
			}
		};

		Node *mHead;
		Node *mTail;
		int mLength;

	public:
		/* Constructors */
		SubList();

		/* Destructor */
		~SubList();

		/* Accessors */
		int getItem(int listIndex, int subsetIndex);
		int getLength();
		int* getSubset(int listIndex);
		int getSupport(int listIndex);

		/* Mutators */
		void setItem(int listIndex, int subsetIndex, int item);
		void setItemSubset(int listIndex, int* subset);
		void setSupport(int listIndex, int support);

		/* Functions */
		void clear();
		bool display(int subsetLength);
		void incrementSupport(int listIndex);
		bool insert(int* itemSubset, int subsetLength);
		bool isEmpty();
		bool isExist(int* itemSubset);
		void outputToFile(int subsetLength, ofstream& out, int* itemTranslation);
		int* removeAt(int listIndex);

		/* Operator Overloading */
		int* operator[](int listIndex);
};

#endif