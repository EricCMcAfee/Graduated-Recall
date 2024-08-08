#pragma once
#include "VocabList.h"

using namespace std;

// reads csv data into a VocabList
void readCSV(string filename, VocabList *list);

// overwrites VocabList data to a csv file
void writeCSV(string filename, VocabList *list);