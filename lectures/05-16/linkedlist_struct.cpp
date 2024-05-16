#include <iostream>

struct Node 
{
    int data;
    Node* next; // point to the next node
};

void deleteAllNodes(Node* head)
{
    Node* temp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }
}

void deleteFirstNode(Node* head)
{
    Node* temp = NULL;
    temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
}

void printAllNodes(Node* head)
{
    while (head != NULL)
    {
        std::cout << head->data << '\n';
        head = head->next;
    }
}

int main() 
{
    // Create the first HEAD node
    Node* head = new Node;
    Node(); // default constructor

    head->data=1;
    head->next = new Node;

    head->next->data = 3;
    head->next->next = new Node;

    head->next->next->data = 6;
    head->next->next->next = NULL;

    deleteFirstNode(head);
    printAllNodes(head);

    return 0;
}