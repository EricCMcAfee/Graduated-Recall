#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "VocabList.h"
#include "FileManagement.h"

using namespace std;

// global list for imported words
VocabList *NEWWORDS = new VocabList();

// global lists for previously studied and sorted words
VocabList *WEAKWORDS = new VocabList();
VocabList *MEDIUMWORDS = new VocabList();
VocabList *STRONGWORDS = new VocabList();

// list of words to study. populated by the studylist function. made global for clarity
VocabList *STUDYLIST = new VocabList();

// global ints to determine how many words will be pulled from each bucket. Will eventually be implemented to be configurable by user
int NUMNEWWORDS = 0;
int NUMWEAKWORDS = 6;
int NUMMEDIUMWORDS = 3;
int NUMSTRONGWORDS = 1;

// function to get integer input from user with error handling
int getIntegerSelection()
{
    string userInput;
    int inputToInt;
    cin >> userInput;
    try
    {
        inputToInt = stoi(userInput);
    }
    catch (invalid_argument userInput)
    {
        cout << "Please enter an appropriate selection..." << "\n";
    }
    return inputToInt;
}

// function for prompting a word from the study list
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
    int userConfidence = 0;
    while (userConfidence < 1 || userConfidence > 3)
    {
        userConfidence = getIntegerSelection();
    }
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

// function for introducing the application and gathering user input for configuration
void runIntroduction()
{
    cout << "Hello and welcome to the Graduated Recall vocabulary application!" << "\n";
    cout << "How many new words would you like to add to your study list today (The recommended default is 10)?" << "\n";

    while (NUMNEWWORDS < 1 || NUMNEWWORDS > 20)
    {
        cout << "Please enter a number between 1 and 20..." << "\n";
        NUMNEWWORDS = getIntegerSelection();
    }
}

int main()
{
    readCSV("NEWWORDS.csv", NEWWORDS);
    readCSV("WEAKWORDS.csv", WEAKWORDS);
    readCSV("MEDIUMWORDS.csv", MEDIUMWORDS);
    readCSV("STRONGWORDS.csv", STRONGWORDS);
    runIntroduction();
    STUDYLIST->CreateStudyList(NEWWORDS, WEAKWORDS, MEDIUMWORDS, STRONGWORDS, NUMNEWWORDS, NUMWEAKWORDS, NUMMEDIUMWORDS, NUMSTRONGWORDS);
    runQuiz(STUDYLIST);
    writeCSV("NEWWORDS.csv", NEWWORDS);
    writeCSV("WEAKWORDS.csv", WEAKWORDS);
    writeCSV("MEDIUMWORDS.csv", MEDIUMWORDS);
    writeCSV("STRONGWORDS.csv", STRONGWORDS);
}