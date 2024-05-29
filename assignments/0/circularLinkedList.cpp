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
    CircularLinkedList() : head(nullptr) {};

    void insert(int value, int index);

    // void remove(int index);

    void display();

    // void search();
};

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

        else
        {
            head->prev->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    else
    {
        int position = 1;
        Node* previous = head;
        Node* current = head->next;

        while (position < index)
        {
            previous = previous->next;
            current = current->next;
            if (current == nullptr)
            {
                break; // position value larger than it should
            }
            position++;
        }

        previous->next = newNode;
        newNode->prev = previous;
        newNode->next = current;
        if (current != nullptr)
        {
            current->prev = newNode;
        }
    }
}

void CircularLinkedList::display()
{
    if (head == nullptr)
    {
        std::cout << "head->NULL";
        return;
    }

    while (head != nullptr)
    {
        std::cout << head->data << "->";
        head = head->next;
    }

    std::cout << head->next;
    return;
}

// Test Cases?
int main()
{
    CircularLinkedList CLL;
    CLL.insert(0, 0);
    CLL.insert(1, 1);
    CLL.insert(2, 2);
    CLL.insert(3, 3);

    CLL.insert(99, 3);

    CLL.display();
}

