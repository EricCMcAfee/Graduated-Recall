#pragma once
#include "VocabList.h"

using namespace std;

void readCSV(string filename, VocabList *list);

void writeCSV(string filename, VocabList *list);