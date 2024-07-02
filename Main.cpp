#include <iostream>
using namespace std;

// principal definitions of structures for both linked lists and trees
struct node
{
    string data;
    node *next;
};

struct linkedList
{
    node *head = NULL;
};

// helper functions to build trees for testing
node *build_three_node_list_helper(int one, int two, int three)
{
    node *top(new node);
    top->data = one;
    top->next = new node;
    top->next->data = two;
    top->next->next = new node;
    top->next->next->data = three;
    top->next->next->next = (NULL);
    return top;
}

// functional implementations of linked list operationd
void linkedlist_print(linkedList list)
{
    if (list.head != NULL)
    {
        node *curr = new node;
        curr = list.head;
        while (curr != nullptr)
        {
            cout << curr->data;
            curr = curr->next;
        }
    }
}

linkedList linkedlist_combine(linkedList list1, linkedList list2)
{
    linkedList combinedlist;
    if (list1.head != nullptr)
    {
        combinedlist.head = list1.head;
    }
    node *curr = combinedlist.head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = list2.head;
    return combinedlist;
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

void linkedlist_append(linkedList list, node *nodetoappend)
{
    if (list.head == NULL)
    {
        list.head = nodetoappend;
    }
    else
    {
        node *cursor = list.head;
        while (cursor != nullptr)
        {
            cursor = cursor->next;
        }
        cursor->next = nodetoappend;
    }
}

void linkedlist_appenddata(linkedList list, string data)
{
    node* nodetoappend = new node;
    nodetoappend->data = data;
    linkedlist_append(list, nodetoappend);
}

void linkedlist_insert()
{
}

int main()
{
    linkedList newWords;
    linkedList hourWords;
    linkedList daywords;
    linkedList weekwords;
}