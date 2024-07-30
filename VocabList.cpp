#include <iostream>
#include "VocabList.h"

using namespace std;

VocabList::VocabList()
{
    head = nullptr;
    tail = nullptr;
}
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

VocabWord *VocabList::GetHead()
{
    return head;
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
        tail->next = nullptr;
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

        VocabWord *cursor = head;
        firstHalf->head = head;
        for (int i = 0; i < count - 1 && cursor != nullptr; i++)
        {
            cursor = cursor->next;
        }
        firstHalf->tail = cursor;
        head = cursor->next;
        firstHalf->tail->next = nullptr;
    }
    return firstHalf;
}

void VocabList::JoinLists(VocabList *toJoin)
{
    if (toJoin->head != nullptr)
    {
        if (this->head == nullptr)
        {
            head = toJoin->head;
            tail = toJoin->tail;
            tail->next = nullptr;
        }
        else
        {
            this->tail->next = toJoin->head;
            this->tail = toJoin->tail;
            this->tail->next = nullptr;
        }
        toJoin->head = nullptr;
        toJoin->head = nullptr;
    }
}

void VocabList::CreateStudyList(VocabList *newWords, VocabList *weakWords, VocabList *strongWords)
{

    this->JoinLists(newWords);

    VocabList *listcursor = weakWords->SplitAt(weakWords->Size() / 2);
    this->JoinLists(listcursor);

    listcursor = strongWords->SplitAt(strongWords->Size() / 4);
    this->JoinLists(listcursor);
}
