/*		Author: Jimmy Griffiths & Walter Proulx
*		Class : CSI-281-01
*		Assignment : Final Project
* 		Date Assigned : November 30, 2017
* 		Due Date : November 5, 2017
*
*		Description :
*			An implementation of the Apriori algorithm. This file contains the definitions for ItemsList class.
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

/*
ItemsList
pre: none
post: an ItemsList will be initialized
purpose: to create an ItemsList so that we can store items
*/
ItemsList::ItemsList()
{
	mHead = NULL;
	mTail = NULL;
	mLength = 0;
}

/*
pre: an ItemsList must exist
post: The ItemsList will be destroyed
purpose: to destroy an ItemsList so that we have no memory leak.
*/
ItemsList::~ItemsList()
{
	clear();

	mHead = NULL;
	mTail = NULL;

	mLength = 0;
}

/*
getItem
pre: an index of an item
post: an itemnumber will be returned
purpose: to get an itemnumber from the list at a certain index
*/
int ItemsList::getItem(int index)
{
	Node *tmp;
	if (index < 0 || index > mLength)
		return -1;

	tmp = mHead;
	for (int i = 0; i < index; i++)
	{
		tmp = tmp->mNext;
	}

	return tmp->mItemNumber;
}

/*
getLength
pre: A list must exist
post: an int of the length of the list will be returned
purpose: to get the length of the list
*/
int ItemsList::getLength()
{
	return mLength;
}

/*
setItem
pre: an index we are looking for, and the new item number
post: an itemnumber in the list at an index will change
purpose: to change the itemnumber of a certain item at an index to something else
*/
void ItemsList::setItem(int index, int item)
{
	if (index > mLength || index < 0)
		return;

	if (mHead == NULL)
		return;

	Node *tmp;
	tmp = mHead;

	for (int i = 0; i < index; i++)
		tmp = tmp->mNext;

	tmp->mItemNumber = item;
}

/*
clear
pre: the list must exist
post: everything in the list will be deleted and mHead and mTail will be set to NULL
purpose: to clear the list of the all items
*/
void ItemsList::clear()
{
	if (mHead == NULL)
		return;

	Node *tmp;
	Node *toBeDeleted;

	tmp = mHead;

	while (tmp != NULL)
	{
		toBeDeleted = tmp;
		tmp = tmp->mNext;
		toBeDeleted->mNext = NULL;

		delete toBeDeleted;
	}
}

/*
display
pre: a list must exist
post: itemnumbers from the list will be output to the screen
purpose: to output every itemnumber in the list to the screen
*/
void ItemsList::display()
{
	if (mHead == NULL)
	{
		cout << "Nothing in list." << endl;
		return;
	}
	Node *tmp;
	tmp = mHead;

	cout << "Items list: {";
	while (tmp != NULL)
	{
		cout << tmp->mItemNumber;
		if (tmp->mNext != NULL)
			cout << ", ";
		tmp = tmp->mNext;
	}

	cout << "}" << endl;
}

/*
insert
pre: an itemnumber that we wish to insert into the list
post: a new node will be inserted, or not. We will return whether we inserted or not. mLength will also be incremented
purpose: to insert new itemnumbers into the list
*/
bool ItemsList::insert(int item)
{
	Node *newNode = new Node(item);
	newNode->mItemNumber = item;

	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}

	else if (item < mHead->mItemNumber)
	{
		newNode->mNext = mHead;
		mHead = newNode;
	}

	else if (item > mTail->mItemNumber)
	{
		mTail->mNext = newNode;
		mTail = newNode;
	}

	else
	{
		Node *tmp, *oneBefore;
		tmp = mHead;
		oneBefore = mHead;
		while (tmp->mItemNumber < item)
		{
			oneBefore = tmp;
			tmp = tmp->mNext;
		}

		if (tmp->mItemNumber != item)
		{
			newNode->mNext = tmp;
			oneBefore->mNext = newNode;
		}

		else
		{
			delete newNode;
			return false;
		}
	}

	mLength++;
	return true;
}

/*
isEmpty
pre: list must exist
post: we will return true or false whether the list is empty or not
purpose: to check if the list is empty or not
*/
bool ItemsList::isEmpty()
{
	if (mHead == NULL)
		return true;

	else
		return false;
}

/*
isExist
pre: the list must exist, and we are getting an item that we wish to check if it exists
post: we will return true or false based on whether the list contains that itemnumbers
purpose: to check if something exists in the list
*/
bool ItemsList::isExist(int item)
{
	Node *tmp;
	tmp = mHead;

	bool found = false;

	while (tmp != NULL && !found)
	{
		if (tmp->mItemNumber == item)
			found = true;

		else if (tmp->mItemNumber > item)
			tmp = NULL;

		else
			tmp = tmp->mNext;
	}

	return found;
}

/*
remove
pre: the itemnumber that we wish to remove
post: we will return true or false based on whether we removed the node or not. mLength will also be decremented
purpose: to remove an item from the list.
*/
bool ItemsList::remove(int item)
{
	if (mHead == NULL)
		return false;

	Node *tmp, *oneBefore, *toBeDel;
	bool found = false;

	tmp = mHead;
	oneBefore = mHead;

	while (tmp != NULL && !found)
	{
		if (tmp->mItemNumber == item)
			found = true;
		else if (tmp->mItemNumber > item)
			tmp = NULL;
		else
		{
			oneBefore = tmp;
			tmp = tmp->mNext;
		}

	}

	if (found)
	{
		toBeDel = tmp;

		if (tmp == mHead)
		{
			if (mHead == mTail)
			{
				mHead = NULL;
				mTail = NULL;
			}

			else
			{
				mHead = tmp->mNext;
			}

		}

		else if (tmp == mTail)
		{
			mTail = oneBefore;
			mTail->mNext = NULL;
		}

		else
		{
			oneBefore->mNext = tmp->mNext;
		}

		toBeDel->mNext = NULL;
		delete toBeDel;
		mLength--;
	}

	return found;
}

/*
removeAt
pre: the list must exist, and we get an index to removes
post: a node will be removed from the list. mLength will be decremented
purpose: to remove a node at a certain index from the list
*/
int ItemsList::removeAt(int index)
{
	Node *tmp, *oneBefore;

	int data;
	int i;

	if (index < 0 || index > mLength)
		return -1;

	else if (mHead != NULL)
	{
		tmp = mHead;
		oneBefore = tmp;

		for (i = 0; i < index; i++)
		{
			oneBefore = tmp;
			tmp = tmp->mNext;
		}

		data = tmp->mItemNumber;

		if (index == 0)
			mHead = tmp->mNext;
		else
			oneBefore->mNext = tmp->mNext;

		delete tmp;

		mLength--;
	}

	return data;
}

/*
operator[]
pre: the list must exist. We are getting the index as if ItemsList was an array
post: An int for an itemnumber will be returned
purpose: to make the code more readable, so we can say something = ItemsList[i] instead of ItemsList.getItem(index)
*/
int ItemsList::operator[] (int index)
{
	return getItem(index);
}