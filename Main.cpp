#include <iostream>
#include "VocabList.h"

using namespace std;

// global list for use across functions
VocabList NEWWORDS;
VocabList DAYWORDS;
VocabList WEEKWORDS;

int main()
{
    VocabList myList;
    myList.Append(myList.InitWord("one", "eins"));
    myList.Append(myList.InitWord("two", "zwei"));
    myList.Append(myList.InitWord("three", "drei"));
    myList.Append(myList.InitWord("four", "vier"));
    myList.Append(myList.InitWord("five", "funf"));

    myList.Append(myList.InitWord("masculine definite article", "der"));
    myList.Append(myList.InitWord("feminine definite article", "die"));
    myList.Append(myList.InitWord("neuter definite article", "das"));

    myList.Append(myList.InitWord("red", "rot"));
    myList.Append(myList.InitWord("yellow", "gelb"));
    myList.Append(myList.InitWord("blue", "blau"));
    myList.Append(myList.InitWord("black", "schwarz"));
    myList.Append(myList.InitWord("white", "weiss"));

    myList.Print();
}