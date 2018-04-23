#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ItemsList.h"
#include "SubList.h"

using namespace std;

/* functions */
void calculateSupport(SubList& sub1, SubList& sub2, bool flipper, bool **transaction, int fileLength, int subsetLength);

string getFileName();
int getItemList(string filename, ItemsList& item);

void generateSubSet1(SubList& sub1, int itemCount);
void generateSubSet2(SubList& sub1, SubList& sub2, int itemCount);
bool generateSubSet(SubList& sub1, SubList& sub2, int itemCount, int subSetNumber, bool subFlipper);

void initializeTransactions(bool **transaction, int* itemTranslation, int itemCount, string filename);

void outputSupport(SubList& sub1, SubList& sub2, bool flipper, ofstream &fout, int subLength, int *itemTranslation);

void pruneSubSet(SubList& sub1, SubList& sub2, bool subFlipper, int subsetLength, int supportMinimum);

int searchItem(int* itemTranslation, int item, int itemCount);
void transferItems(ItemsList& items, int* itemTranslation);

#endif
