#include <iostream>

struct Node
{
    int data;
    Node* link;
    Node(int val) : data(val), link(nullptr) {}
};

typedef Node* NodePtr;

NodePtr searchNode(NodePtr head, int target) 
{
    NodePtr tempPtr = head;

    while (tempPtr != nullptr)
    {
        if (tempPtr->data == target)
        {
            return tempPtr;
        }

        tempPtr = tempPtr->link;
    }

    return nullptr;
}

void printAllNodes(NodePtr head)
{
    while (head != NULL)
    {
        std::cout << head->data << '\n';
        head = head->link;
    }
}

int main()
{
    Node* head = new Node(1);
    head->link = new Node(2);
    head->link->link = new Node(3);
    head->link->link->link = new Node(5);

    printAllNodes(head);

    std::cout << "Found: " << searchNode(head, 1)->data << '\n';
}