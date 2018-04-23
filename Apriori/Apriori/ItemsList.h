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
#ifndef ITEMS_LIST_H
#define ITEMS_LIST_H

#include <iostream>

using namespace std;

class ItemsList
{
	private:
		struct Node
		{
			int mItemNumber;
			Node *mNext;

			Node()
			{
				mItemNumber = -1;
				mNext = NULL;
			}

			Node(int itemNumber)
			{
				mItemNumber = mItemNumber;
				mNext = NULL;
			}
		};

		Node *mHead;
		Node *mTail;
		int mLength;

	public:
		ItemsList();
	
		~ItemsList();

		int getItem(int index);
		int getLength();

		void setItem(int index, int item);

		void clear();
		void display();
		bool insert(int item);
		bool isEmpty();
		bool isExist(int item);
		bool remove(int item);
		int removeAt(int index);

		int operator[] (int index);
};

#endif