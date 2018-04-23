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
#include "SubList.h"

/*      Pre:  constructor
 *     Post:  intialize object variables
 *  Purpose:  to initialize Sublist object
 ********************************************************************/
SubList::SubList()
{
	mHead = NULL;
	mTail = NULL;
	mLength = 0;
}

/*      Pre:  destructor
 *     Post:  destroys variables
 *  Purpose:  to deconstruct Sublist object
 ********************************************************************/
SubList::~SubList()
{
	// destroy nodes
	clear();

	// clear pointers and reset length
	mHead = NULL;
	mTail = NULL;
	mLength = 0;

}

/*      Pre:  int, int
 *     Post:  int
 *  Purpose:  to get a specific item from a subset in the sublist
 ********************************************************************/
int SubList::getItem(int listIndex, int subsetIndex)
{
	Node *temp = mHead;

	if (temp != NULL)
	{
		for (int x = 0; x < listIndex; x++)
		{
			temp = temp->mNext;
		}

		return temp->mItemSubset[subsetIndex];
	}
	
	return -1;
}

/*      Pre:  none
 *     Post:  int
 *  Purpose:  retrieves length of SubList object
 ********************************************************************/
int SubList::getLength()
{
	return mLength;
}

/*      Pre:  int
 *     Post:  int[]
 *  Purpose:  retrieves the subset of the specified list index
 ********************************************************************/
int* SubList::getSubset(int listIndex)
{
	Node *temp = mHead;

	for (int x = 0; x < listIndex; x++)
	{
		temp = temp->mNext;
	}

	return temp->mItemSubset;
}

/*      Pre:  int
 *     Post:  int
 *  Purpose:  retrieves the support of a subset in SubList object
 ********************************************************************/
int SubList::getSupport(int listIndex)
{
	Node *temp = mHead;

	for (int x = 0; x < listIndex; x++)
	{
		temp = temp->mNext;
	}

	return temp->mSupport;
}

/*      Pre:  int, int, int
 *     Post:  sets item in subset
 *  Purpose:  to initialize an item in a subset in the SubList object
 ********************************************************************/
void SubList::setItem(int listIndex, int subsetIndex, int item)
{
	Node *temp = mHead;

	for (int x = 0; x < listIndex; x++)
	{
		temp = temp->mNext;
	}

	temp->mItemSubset[subsetIndex] = item;
}

/*      Pre:  int, int[]
 *     Post:  sets subset
 *  Purpose:  to initialize a subset in the SubList object
 ********************************************************************/
void SubList::setItemSubset(int listIndex, int* subset)
{
	Node *temp = mHead;

	for (int x = 0; x < listIndex; x++)
	{
		temp = temp->mNext;
	}

	temp->mItemSubset = subset;
}

/*      Pre:  int, int
 *     Post:  sets support
 *  Purpose:  to initialize a support in the SubList object
 ********************************************************************/
void SubList::setSupport(int listIndex, int support)
{
	Node *temp = mHead;

	for (int x = 0; x < listIndex; x++)
	{
		temp = temp->mNext;
	}

	temp->mSupport = support;
}

/*      Pre:  none
 *     Post:  deletes list
 *  Purpose:  to destroy all nodes and reset variables of SubList
 *			  object
 ********************************************************************/
void SubList::clear()
{
	Node *temp, *toBeDeleted;

	temp = mHead;

	// remove list node by node
	while (temp != NULL)
	{
		toBeDeleted = temp;
		temp = temp->mNext;
		toBeDeleted->mNext = NULL;

		delete toBeDeleted;
	}

	// reinitialize the pointers
	mHead = NULL;
	mTail = NULL;
	mLength = 0;

}

/*      Pre:  int
 *     Post:  outputs list to standard output
 *  Purpose:  to show all subsets in a list
 ********************************************************************/
bool SubList::display(int subsetLength)
{
	int subsetIndex;
	Node *temp = mHead;

	if (temp == NULL)
	{
		cout << "DISPLAY ERROR: No " << subsetLength << "-subsets present." << endl;
		return false;
	}

	while (temp != NULL)
	{
		for (subsetIndex = 0; subsetIndex < subsetLength; subsetIndex++)
		{
			if (subsetIndex == 0)
			{
				cout << "{ " << temp->mItemSubset[subsetIndex];
			}
			else
			{
				cout << ", " << temp->mItemSubset[subsetIndex];

			}
		}

		cout << " } | Support: " << temp->mSupport << endl;
		temp = temp->mNext;
	}

	return true;
}

/*      Pre:  int
 *     Post:  increment support
 *  Purpose:  to increment a specific subsets support
 ********************************************************************/
void SubList::incrementSupport(int listIndex)
{
	Node *temp = mHead;

	for (int x = 0; x < listIndex; x++)
	{
		temp = temp->mNext;
	}

	temp->mSupport++;
}

/*      Pre:  int[]
 *     Post:  increment support
 *  Purpose:  to increment a specific subsets support
 ********************************************************************/
bool SubList::insert(int* itemSubset, int subsetLength)
{
	Node *newNode;

	newNode = new Node(itemSubset, subsetLength);

	if (newNode == NULL)
	{
		return false;
	}

	if (mTail == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		mTail->mNext = newNode;
		mTail = newNode;
	}

	mLength++;

	return true;
}

/*      Pre:  none
 *     Post:  bool
 *  Purpose:  returns true if SubList object contains no subsets
 ********************************************************************/
bool SubList::isEmpty()
{
	return (mHead == NULL);
}

/*      Pre:  int[]
 *     Post:  bool
 *  Purpose:  returns true if a specific subset exists in SubList
 *			  object
 ********************************************************************/
bool SubList::isExist(int* itemSubset)
{
	Node *temp = mHead;

	while (temp != NULL)
	{
		if (temp->mItemSubset == itemSubset)
		{
			return true;
		}

		temp = temp->mNext;
	}

	return false;
}

/*      Pre:  int, ofstream
 *     Post:  file output
 *  Purpose:  outputs the subset and support from SubList object,
 *			  and will throw error if the subset cannot be generated
 *			  NOTE: this error can be okay if the pruning process has
 *					stopped larger subsets from being created
 ********************************************************************/
void SubList::outputToFile(int subsetLength, ofstream& out, int* itemTranslation)
{
	int subsetIndex;
	Node *temp = mHead;

	if (temp == NULL)
	{
		out << "OUTPUT ERROR: No " << subsetLength << "-subsets present." << endl;
		return;
	}

	while (temp != NULL)
	{
		for (subsetIndex = 0; subsetIndex < subsetLength; subsetIndex++)
		{
			if (subsetIndex == 0)
			{
				out << "{ " << itemTranslation[temp->mItemSubset[subsetIndex]];
			}
			else
			{
				out << ", " << itemTranslation[temp->mItemSubset[subsetIndex]];

			}
		}

		out << " } | Support: " << temp->mSupport << endl;
		temp = temp->mNext;
	}
}

/*      Pre:  int
 *     Post:  int
 *  Purpose:  returns data of the removed subset at the specified
 *			  index
 ********************************************************************/
int* SubList::removeAt(int listIndex)
{
	Node *temp, *oneBefore;
	int *data;

	data = new int(0);

	if (listIndex < 0 || listIndex > mLength);
	else if (mHead != NULL)
	{
		temp = mHead;
		oneBefore = mHead;

		for (int x = 0; x < listIndex; x++)
		{
			oneBefore = temp;
			temp = temp->mNext;
		}

		data = temp->mItemSubset;

		if (listIndex == 0)
		{
			mHead = temp->mNext;
		}
		else if (temp == mTail)
		{
			mTail = oneBefore;
			mTail->mNext = NULL;
		}
		else
		{
			oneBefore->mNext = temp->mNext;
		}

		temp->mNext = NULL;
		delete temp;
		mLength--;
	}

	return data;
}

/*      Pre:  int
 *     Post:  int[]
 *  Purpose:  returns data of the removed subset at the specified
 *			  index
 ********************************************************************/
int* SubList::operator[](int listIndex)
{
	return getSubset(listIndex);
}