#include <iostream>

// Node Structure
struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}; // Default Constructor
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}; // Data Constructor
};

// Circular Doubly Linked List Class Definition
class CircularLinkedList
{
private:
    Node* head;

public:
    // Default Constructor
    CircularLinkedList() : head(nullptr) {};

    // Insertion
    void insert(int value, int index);

    // Deletion
    void remove(int index);

    // Display
    void display();

    // Search 
    void search();
}

// Method Definition
void CircularLinkedList::insert(int value, int index)
{
    Node* newNode = new Node(value);
    if (index == 0)
    {
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        
    }
    
}

// Test Cases?
int main()
{
    CircularLinkedList CLL(1);
}

