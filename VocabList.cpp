#include <iostream>
#include "VocabList.h"

using namespace std;

void VocabList::Print()
{
    if (head != NULL)
    {
        VocabWord *cursor = head;
        while (cursor != nullptr)
        {
            cout << cursor->English << " : " << cursor->German << endl;
            cursor = cursor->next;
        }
    }
}
int VocabList::Size()
{
    int size = 0;
    if (head != nullptr)
    {
        VocabWord *cursor = head;
        while (cursor != nullptr)
        {
            size++;
            cursor = cursor->next;
        }
    }
    return size;
}

VocabWord *VocabList::InitWord(string english, string german)
{
    VocabWord *word = new VocabWord();
    word->English = english;
    word->German = german;
    return word;
}

void VocabList::Append(VocabWord *toAppend)
{
    if (head == nullptr)
    {
        head = toAppend;
        tail = toAppend;
    }
    else
    {
        tail->next = toAppend;
        toAppend->previous = tail;
        tail = toAppend;
    }
}
void VocabList::Remove(VocabWord *toRemove)
{
    VocabWord *sucNode = toRemove->next;
    VocabWord *predNode = toRemove->previous;
    if (sucNode != nullptr)
    {
        sucNode->previous = predNode;
    }
    if (predNode != nullptr)
    {
        predNode->next = sucNode;
    }
    if (toRemove == head)
    {
        head = sucNode;
    }
    if (toRemove == tail)
    {
        tail = predNode;
    }
}
VocabList *VocabList::SplitAt(int count)
{

    VocabList *firstHalf = new VocabList();
    if (head != NULL)
    {

        VocabWord *cursor = new VocabWord();
        firstHalf->head = head;
        for (int i = 0; i < count && cursor != nullptr; i++)
        {
            cursor = cursor->next;
        }
        firstHalf->tail = cursor;
        head = cursor;
    }
    return firstHalf;
}

VocabList *JoinLists(VocabList *toJoin)
{
}
