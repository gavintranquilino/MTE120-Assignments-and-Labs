#include <iostream>

struct Node 
{
    int data;
    Node* link; 
};

typedef Node* NodePtr;

class LinkedList
{
private:
public:
};

void headInsert(NodePtr& head, int theData);
void printAllNodes(NodePtr& head);

int main()
{
    NodePtr head = new Node;
    headInsert(head, 1);
    headInsert(head, 2);
    printAllNodes(head);

    // TODO: reads 1 more than needed

    return 0;
}

void headInsert(NodePtr& head, int theData)
{
    NodePtr tempPtr;
    tempPtr = new Node;
    tempPtr->data = theData;
    tempPtr->link = head;
    head = tempPtr;
}

void printAllNodes(NodePtr& head)
{
    while (head != NULL)
    {
        std::cout << head->data << '\n';
        head = head->link;
    }
}