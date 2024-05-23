// GAVIN'S SINGLY LINKED LIST

#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        Node* head = nullptr;
    }

    LinkedList(int value)
    {
        head = new Node;
        head->data = value;
        head->next = nullptr;
    }

    void insert(Node*& head, int value, int position) // Node*& so it doesn;t make a copy of the Node*
    {
        // make the new node to insert
        Node* newNode;
        newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        // if position = 0
        if (position == 0)
        {
            if (head == nullptr) // no head :(
            {
                head = newNode;
                return;
            }
            
            else // size > 0 
            {
                newNode->next = head;     
                head = newNode;           
                return;
            }
        }

        // if position > 0 
        else
        {
            Node* prev = head;
            Node* curr = head->next;
            int index = 1; // because curr starts at index 1
            while (index < position && prev->next != nullptr) // check if prev has something to jump to 
            {
                prev = prev->next;
                curr = curr->next; // jump both

                if (curr == nullptr) // now that you jumped, is curr empty?
                    break;

                index++; // update index of curr after jump
            }
        }
    }

    void remove(Node* head, int position)
    {
        if (position == 0 && head != nullptr)
        {
            Node* temp;
            temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
            return;
        }

        Node* prev;
        Node* curr;

        prev = head;
        curr = head->next;

        int index = 1;
        while (index < position)
        {
            if (curr->next == nullptr)
            {
                break;
            }

            prev = prev->next;
            curr = curr->next;
            index++;
        }

        prev->next = curr->next;
        delete curr;
        curr = nullptr;
    }
};

int main()
{
    LinkedList list;
}