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
//#include "ItemsList.h"
//#include "SubList.h"
//#include "functions.h"
//
//int main()
//{
//	/* making variables */
//	SubList test;
//	int *subset, *subset2;
//
//	subset = new int[3];
//	subset[0] = 10;
//	subset[1] = 11;
//	subset[2] = 12;
//
//	/* testing SubList object */
//	cout << "Expecting: " << endl 
//		 << "{ 10, 11, 12 } | Support: 0" << endl << endl;
//	test.insert(subset);
//	test.display(3);
//
//	cout << "Expecting: " << endl
//		<< "{ 10, 11, 12 } | Support: 1" << endl << endl;
//	test.incrementSupport(0);
//	test.display(3);
//
//	cout << "Expecting: " << endl
//		<< "{ 11, 11, 12 } | Support: 1" << endl << endl;
//	test.setItem(0, 0, 11);
//	test.display(3);
//
//	cout << "Expecting: " << endl
//		<< "{ 11, 11, 12 } | Support: 1" << endl
//		<< "{ 14, 15, 16 } | Support: 0" << endl << endl;
//	subset = new int[3];
//	subset[0] = 14;
//	subset[1] = 15;
//	subset[2] = 16;
//	test.insert(subset);
//	test.display(3);
//
//	cout << "Expecting: " << endl
//		<< "{ 11, 11, 12 } | Support: 1" << endl
//		<< "{ 1000, 1001, 1002 } | Support: 0" << endl << endl;
//	subset2 = new int[3];
//	subset2[0] = 1000;
//	subset2[1] = 1001;
//	subset2[2] = 1002;
//	test.setItemSubset(1, subset2);
//	test.display(3);
//
//	cout << "Expecting: " << endl
//		<< "{ 1000, 1001, 1002 } | Support: 0" << endl << endl;
//	subset[0] = 11;
//	subset[1] = 11;
//	subset[2] = 12;
//	test.removeAt(0);
//	test.display(3);
//
//	cout << endl << "Deleting list..." << endl;
//	cout << "Expecting 0: " << test.isEmpty() << endl;
//	cout << "Expecting 1: " << test.isExist(subset2) << endl;
//	test.clear();
//	cout << "Expecting 1: " << test.isEmpty() << endl;
//	cout << "Expecting ERROR: " << endl;
//	test.display(3);
//
//	system("pause");
//	return 0;
//}