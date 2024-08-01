#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "FileManagement.h"
#include "VocabList.h"

using namespace std;

// function to read in csv data to the appropriate VocabList
void readCSV(string filename, VocabList *list)
{
    ifstream inputFile;
    string path = (filesystem::current_path().string()) + "\\" + "VocabLists" + "\\" + filename;
    inputFile.open(path);

    string inputLine = "";
    string german;
    string english;

    while (getline(inputFile, inputLine))
    {
        stringstream string(inputLine);
        getline(string, german, ',');
        getline(string, english, ',');
        list->Append(list->InitWord(english, german));
        inputLine = "";
        german = "";
        english = "";
    }
    inputFile.close();
}

void writeCSV(string filename, VocabList *list)
{
    ofstream outputFile;
    string path = (filesystem::current_path().string()) + "\\" + "VocabLists" + "\\" + filename;
    outputFile.open(path);

    VocabWord *cursor = list->GetHead();
    while (cursor != nullptr)
    {
        outputFile << cursor->English << ',' << cursor->German << '\n';
        cursor = cursor->next;
    }
    outputFile.close();
}