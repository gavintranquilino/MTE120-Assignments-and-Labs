#include <iostream>

struct Node 
{
    int data;
    Node *next; // point to the next node
};

int main() 
{
    // Create the first HEAD node
    Node *head = new Node;
    Node(); // default constructor

    // Init values
    head->data = 1; // what does the -> operator do? (It is used to access the member of a structure using a pointer.)
    head->next = NULL;

    // these are the same output
    std::cout << (*head).data << '\n';
    std::cout << head->data << '\n';
}