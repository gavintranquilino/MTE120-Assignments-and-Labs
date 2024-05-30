#include <iostream>

class CircularLinkedList
{
private:
    struct Node
    {
        int data;
        Node* next;
        Node* prev;
        Node() : data(0), next(nullptr), prev(nullptr) {}; // Default Constructor
        Node(int value) : data(value), next(nullptr), prev(nullptr) {}; // Data Constructor
    };
    Node* head;
    int size;

public:
    CircularLinkedList() : head(nullptr), size(0) {};

    void insert(int value, int index);

    // void remove(int index);

    void displayFwd();
    void displayBkwd();

    // void search();
};

// Method Definition
void CircularLinkedList::insert(int value, int index)
{
    Node* newNode = new Node(value);

    if (index > size)
    {
        std::cout << "Invalid Position";
    }

    if (index == 0)
    {
        if (head == nullptr) // size 0
        {
            head = newNode;
            head->next = head;
            head->prev = head;
            size++;
            return;
        }

        else // size 1
        {
            head->prev = newNode;
            head->next = newNode;
            newNode->next = head;
            newNode->prev = head;
            head = newNode;
            size++;
            return;
        }
    }

    Node* previous = head->prev;
    Node* current = head;

    int position = 0;
    while (position < index)
    {
        previous = previous->next;
        current = current->next;
        position++;
    }
    // left to right
    previous->next = newNode;
    newNode->prev = previous;
    newNode->next = current;
    current->prev = newNode;
    size++;
}

void CircularLinkedList::displayFwd()
{
    if (head == nullptr)
    {
        std::cout << "head->NULL";
        return;
    }
    
    Node* curr = head;

    for (int i=0; i<size; i++)
    {
        std::cout << curr->data << "->";
        curr = curr->next;
    }
    std::cout << '\n';
    return;
}

void CircularLinkedList::displayBkwd()
{
    if (head == nullptr)
    {
        std::cout << "head->NULL";
        return;
    }
    
    Node* tail = head->prev;

    for (int i=0; i<size; i++)
    {
        std::cout << tail->data << "->";
        tail = tail->prev;
    }
    std::cout << '\n';
    return;
}

// Test Cases?
int main()
{
    CircularLinkedList CLL;
    CLL.insert(1, 0);
    CLL.insert(0, 0);
    CLL.insert(2, 2);
    CLL.insert(3, 3);

    std::cout << "Forward ";
    CLL.displayFwd();
    std::cout << "Backward ";
    CLL.displayBkwd();
}

