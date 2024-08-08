#pragma once
using namespace std;

struct VocabWord
{
    VocabWord *next;
    VocabWord *previous;
    string English;
    string German;
};
class VocabList

{
public:
    // defines the VocabList as a class with pointers to the first and last VocabWords of the list.
    VocabList();

    // prints each VocabWord in VocabList.
    void Print();

    // returns the number of VocabWords in a VocabList.
    int Size();

    // for accessing private member.
    VocabWord *GetHead();

    // for accessing private member.
    VocabWord *GetTail();

    // creates a new VocabWord and initialized the english and german string as those passed in.
    VocabWord *InitWord(string english, string german);

    // appends a VocabWord to the VocabList. NOTE: this will also disconnect the appended VocabWord from its "next" VocabWord.
    void Append(VocabWord *toAppend);

    // removes a word from the VocabList.
    void Remove(VocabWord *toRemove);

    // returns the list the function is called on, truncated a number of VocabWords equal to "count". The remaining words remain part of the ogirinal list. All head and tail pointers are updated.
    VocabList *SplitAt(int count);

    // joins the passed in list to the list the function is called on. Deletes the passed in list.
    void JoinLists(VocabList *toJoin);
    
    // creates the StudyList with a user selected number of words from the newWords list and an algorithm selected number of words from each of the sorted lists.
    void CreateStudyList(VocabList *newWords, VocabList *weakWords, VocabList *mediumWords, VocabList *strongWords, int numNewWords, int numWeakWords, int numMediumWords, int numStrongWords);

private:
    VocabWord *head;
    VocabWord *tail;
};