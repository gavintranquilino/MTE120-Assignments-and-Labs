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

    void deleteLastOccurence(int index);

    void displayFwd();
    void displayBkwd();

    int search(int value);
};

// Method Definition
void CircularLinkedList::insert(int value, int index)
{
    Node* newNode = new Node(value);

    if (index > size)
    {
        std::cout << "Invalid Position\n";
        return;
    }

    if (head == nullptr)
    {
        if (index == 0) // size 0
        {
            head = newNode;
            head->next = head;
            head->prev = head;
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
    if (size == 1)
    {
        head = newNode;
    }
    size++;
}

void CircularLinkedList::deleteLastOccurence(int value)
{
    // there is no list
    if (head == nullptr)
    {
        std::cout << "so no head\n";
    }

    // there is just 1 thing in the list
    else if (head->next == head && head->prev == head && head->data == value)
    {
        delete head;
        head = nullptr;
        size--;
    }

    // everything else
    else
    {
        Node* curr = head;
        while (curr->prev != head && curr->prev->data != value)
        {
            curr = curr->prev;
        }

        if (curr->prev->data == value)
        {
            Node* deleteMe = curr->prev;
            deleteMe->prev->next = deleteMe->next;
            deleteMe->next->prev = deleteMe->prev;

            if (deleteMe == head)
            {
                head = head->next;
            }

            delete deleteMe;
            deleteMe = nullptr;
            size--;
            std::cout << "get deleted\n";
        }

        else 
        {
            std::cout << "cant find\n";
        }

    }

    return;
}

void CircularLinkedList::displayFwd()
{
    Node* curr = head;
    do
    {
        std::cout << curr->data << "->";
        curr = curr->next;
    } while (curr != head);
    std::cout << '\n';
   return;
}

void CircularLinkedList::displayBkwd()
{
    Node* tail = head->prev;
    do
    {
        std::cout << tail->data << "->";
        tail = tail->prev;
    } while (tail != head->prev);
    std::cout << '\n';
    return;
}

int CircularLinkedList::search(int value)
{
    Node* curr = head;
    int index = 0;

    while (curr->data != value && curr->next != head)
    {
        curr = curr->next;
        index++;
    }

    if (curr->next == head && curr->data != value)
    {
        return -1; // not found
    }

    else
    {
        return index;
    }
}

int main()
{
    CircularLinkedList CLL;
    CLL.insert(1, 0);
    CLL.insert(0, 0);
    CLL.insert(2, 2);
    CLL.insert(3, 3);

    CLL.insert(3, 6);

    CLL.insert(69, 2);
    CLL.insert(69, 4);
    CLL.insert(420, 0);

    std::cout << "Forward ";
    CLL.displayFwd();
    std::cout << "Backward ";
    CLL.displayBkwd();

    CLL.deleteLastOccurence(69);
    std::cout << "Forward ";
    CLL.displayFwd();
    std::cout << "Backward ";
    CLL.displayBkwd();

    std::cout << "found at: " << CLL.search(420) << '\n';
    std::cout << "found at: " << CLL.search(999) << '\n';

    return 0;
}