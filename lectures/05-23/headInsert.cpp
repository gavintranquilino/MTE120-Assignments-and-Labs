#include <iostream>

struct Node
{
    int data;
    Node* link;
};

typedef Node* NodePtr;

void headInsert(NodePtr& head, int data) // ADD NODE TO HEAD OF LINKEDLIST
{
    NodePtr tempPtr;
    tempPtr = new Node;

    tempPtr->data = data;

    tempPtr->link = head;

    head = tempPtr;
}