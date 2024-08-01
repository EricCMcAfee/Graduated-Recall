#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "VocabList.h"
#include "FileManagement.h"

using namespace std;

// global list for imported words
VocabList *NEWWORDS = new VocabList();

//global lists for previously studied and sorted words
VocabList *WEAKWORDS = new VocabList();
VocabList *MEDIUMWORDS = new VocabList();
VocabList *STRONGWORDS = new VocabList();

// list of words to study. populated by the studylist function. made global for clarity
VocabList *STUDYLIST = new VocabList();

// global ints to determine how many words will be pulled from each bucket. Will eventually be implemented to be configurable by user
int NUMNEWWORDS = 10;
int NUMWEAKWORDS = 6;
int NUMMEDIUMWORDS = 3;
int NUMSTRONGWORDS = 1;

// function for prompting a question
void promptQuestion(VocabWord *word)
{
    if (word == STUDYLIST->GetHead())
    {
        cout << "First Word!" << endl;
    }
    else
    {
        cout << "Next Word!" << endl;
    }
    string userWait;
    cout << "English: " << word->English << endl
         << "German : ";
    cin >> userWait;
    cin.clear();
    cout << "Correct answer: " << word->German << endl;
    cout << "Please enter 1 if you missed it, 2 if it took you a moment, and 3 if you know it well...";
    int userConfidence;
    cin >> userConfidence;
    switch (userConfidence)
    {
    case 1:
        WEAKWORDS->Append(word);
        break;
    case 2:
        MEDIUMWORDS->Append(word);
        break;
    case 3:
        STRONGWORDS->Append(word);
        break;
    }
    cin.clear();
}
// function for running the quiz
void runQuiz(VocabList *studyList)
{
    VocabWord *cursor = studyList->GetHead();
    while (cursor != nullptr)
    {

        VocabWord *toPrompt = cursor;
        cursor = cursor->next;
        promptQuestion(toPrompt);
    }
}

void handDrawLists(VocabList *&newWords, VocabList *&weakWords, VocabList *&strongWords)
{

    newWords = new VocabList();
    newWords->Append(newWords->InitWord("one", "eins"));
    newWords->Append(newWords->InitWord("two", "zwei"));
    newWords->Append(newWords->InitWord("three", "drei"));
    newWords->Append(newWords->InitWord("four", "vier"));
    newWords->Append(newWords->InitWord("five", "funf"));

    weakWords = new VocabList();
    weakWords->Append(weakWords->InitWord("masculine definite article", "der"));
    weakWords->Append(weakWords->InitWord("feminine definite article", "die"));
    weakWords->Append(weakWords->InitWord("neuter definite article", "das"));

    strongWords = new VocabList();
    strongWords->Append(strongWords->InitWord("red", "rot"));
    strongWords->Append(strongWords->InitWord("yellow", "gelb"));
    strongWords->Append(strongWords->InitWord("blue", "blau"));
    strongWords->Append(strongWords->InitWord("black", "schwarz"));
    strongWords->Append(strongWords->InitWord("white", "weiss"));
}

int main()
{
    readCSV("NEWWORDS.csv", NEWWORDS);
    readCSV("WEAKWORDS.csv", WEAKWORDS);
    readCSV("MEDIUMWORDS.csv", MEDIUMWORDS);
    readCSV("STRONGWORDS.csv", STRONGWORDS);
    STUDYLIST->CreateStudyList(NEWWORDS, WEAKWORDS, MEDIUMWORDS, STRONGWORDS, NUMNEWWORDS, NUMWEAKWORDS, NUMMEDIUMWORDS, NUMSTRONGWORDS);
    runQuiz(STUDYLIST);
    writeCSV("NEWWORDS.csv", NEWWORDS);
    writeCSV("WEAKWORDS.csv", WEAKWORDS);
    writeCSV("MEDIUMWORDS.csv", MEDIUMWORDS);
    writeCSV("STRONGWORDS.csv", STRONGWORDS);
}