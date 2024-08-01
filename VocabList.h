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

    VocabList();

    void Print();

    int Size();

    VocabWord *GetHead();

    VocabWord *GetTail();

    VocabWord *InitWord(string english, string german);

    void Append(VocabWord *toAppend);

    void Remove(VocabWord *toRemove);

    VocabList *SplitAt(int count);

    void JoinLists(VocabList *toJoin);

    void CreateStudyList (VocabList * newWords, VocabList* weakWords, VocabList *mediumWords, VocabList *strongWords, int numNewWords, int numWeakWords, int numMediumWords, int numStrongWords);

private:
    VocabWord *head;
    VocabWord *tail;
};