#include <iostream>
using namespace std;

// principal definitions of structures for both linked lists and trees
struct node
{
    string data;
    node *next = nullptr;
};

struct linkedList
{
    node *head = NULL;
};

// global list for use across functions
linkedList NEWWORDS;
linkedList DAYWORDS;
linkedList WEEKWORDS;

// functional implementations of linked list operations
void linkedlist_print(linkedList list)
{
    if (list.head != NULL)
    {
        node *curr = new node;
        curr = list.head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

int linkedlist_size(linkedList list)
{
    int size = 0;
    node *curr = list.head;
    while (curr != nullptr)
    {
        size++;
        curr = curr->next;
    }
    return size;
}

void linkedlist_append(linkedList &list, node *nodetoappend)
{
    if (list.head == NULL)
    {
        list.head = nodetoappend;
    }
    else
    {
        node *cursor = list.head;
        while (cursor->next != nullptr)
        {
            cursor = cursor->next;
        }
        cursor->next = nodetoappend;
    }
}

void linkedlist_append_new(linkedList &list, string data)
{
    node *nodetoappend = new node;
    nodetoappend->data = data;
    linkedlist_append(list, nodetoappend);
}

void linkedList_remove(linkedList list, int offset)
{
    node *currNode = list.head;
    if (offset == 0)
    {
        list.head = list.head->next;
    }
    else
    {
        for (int i = 0; i < offset - 1; i++)
        {
            currNode = currNode->next;
        }
        currNode->next = currNode->next->next;
    }
}

linkedList linkedlist_split_at(linkedList &list, int count)
{
    linkedList firstHalf;
    if (list.head != NULL)
    {
        firstHalf.head = list.head;
        node *curr = list.head;
        node *prev;
        for (int i = 0; i < count && curr != nullptr; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        list.head = curr;
        prev->next = nullptr;
    }
    return firstHalf;
}

linkedList words_to_study(linkedList &NEWWORDS, linkedList &DAYWORDS, linkedList &WEEKWORDS)
{
    linkedList newList;
    linkedlist_append(newList, linkedlist_split_at(NEWWORDS, 3).head);
    linkedlist_append(newList, linkedlist_split_at(DAYWORDS, 2).head);
    linkedlist_append(newList, linkedlist_split_at(WEEKWORDS, 1).head);
    return newList;
}
void ask_question(node *node)
{
    cout << "Rate how well you know this word from 1 to 3..." << endl;
    cout << node->data << endl;
    int userconfidence = 0;
    cin >> userconfidence;
    switch (userconfidence)
    {
    case 1:
        linkedlist_append_new(NEWWORDS, node->data);
        break;
    case 2:
        linkedlist_append_new(DAYWORDS, node->data);
        break;
    case 3:
        linkedlist_append_new(WEEKWORDS, node->data);
        break;
    }
}

void run_quiz(linkedList list)
{
    node *curr = list.head;
    while (curr != nullptr)
    {
        ask_question(curr);
        curr = curr->next;
    }
}

int main()
{
    linkedlist_append_new(NEWWORDS, "eins");
    linkedlist_append_new(NEWWORDS, "zwei");
    linkedlist_append_new(NEWWORDS, "drei");
    linkedlist_append_new(NEWWORDS, "vier");
    linkedlist_append_new(NEWWORDS, "funf");

    linkedlist_append_new(DAYWORDS, "der");
    linkedlist_append_new(DAYWORDS, "den");
    linkedlist_append_new(DAYWORDS, "dem");
    linkedlist_append_new(DAYWORDS, "die");
    linkedlist_append_new(DAYWORDS, "das");

    linkedlist_append_new(WEEKWORDS, "Prost!");
    linkedlist_append_new(WEEKWORDS, "G'suffa!");

    linkedList toStudy = words_to_study(NEWWORDS, DAYWORDS, WEEKWORDS);
    run_quiz(toStudy);
}