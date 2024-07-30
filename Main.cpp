#include <iostream>
#include "VocabList.h"

using namespace std;

// global lists for imported words
VocabList *NEWWORDS;
VocabList *WEAKWORDS;
VocabList *STRONGWORDS;

// global list for clarity
VocabList *STUDYLIST = new VocabList();

// global int for storing grade throughout execution
int GRADE = 0;

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
    cout << word->German << endl;
    cout << "Please enter 1 if you missed it, 2 if it took you a moment, and 3 if you know it well...";
    int userConfidence;
    cin >> userConfidence;
    switch (userConfidence)
    {
    case 1:
        NEWWORDS->Append(word);
        break;
    case 2:
        WEAKWORDS->Append(word);
        break;
    case 3:
        STRONGWORDS->Append(word);
        break;
    }
    cin.clear();
}
// function for running the quiz
void runTest(VocabList *studyList)
{
    VocabWord *cursor = studyList->GetHead();
    while (cursor != nullptr)
    {

        VocabWord *toPrompt = cursor;
        cursor = cursor->next;
        promptQuestion(toPrompt);
    }
}
// helper function to build a simluated vocab list for testing
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
    // to be replaced with import functionality from excel
    handDrawLists(NEWWORDS, WEAKWORDS, STRONGWORDS);

    NEWWORDS->Print();
    cout << endl;
    WEAKWORDS->Print();
    cout << endl;
    STRONGWORDS->Print();
    cout << endl;

    STUDYLIST->CreateStudyList(NEWWORDS, WEAKWORDS, STRONGWORDS);
    STUDYLIST->Print();
    cout << endl;

    runTest(STUDYLIST);

    NEWWORDS->Print();
    cout << endl;
    WEAKWORDS->Print();
    cout << endl;
    STRONGWORDS->Print();
    cout << endl;
}