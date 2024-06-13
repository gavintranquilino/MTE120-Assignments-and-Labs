// Doubly-Linked version of a circular linked list

#include <iostream>

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int x=0): data(x) {};
    };

public:
    Node *head;
    int size;

    void displayBkwd();

    CircularLinkedList() {
        size = 0;
        head = nullptr;
    };

    // Insertion function
    void insert(int num) {
        if (size == 0) {
            head = new Node(num);
            head->next = head;
            head->prev = head;
        } else {
            Node *newNode = new Node(num);
            
            head->prev->next = newNode;

            newNode->next = head;
            newNode->prev = head->prev;
            
            head->prev = newNode;
        }
        size++;
    }

    void remove(int num) {
        if (size == 0)
            std::cout << "Empty list." << std::endl;

        else if (size == 1 && head->data == num) {
            delete head;
            head = nullptr;
            size--;
        }
        
        else {
            Node *temp = head;
            while (temp->prev->data != num && temp->prev != head) {
                temp = temp->prev;
            }
            
            if (temp->prev == head && temp->prev->data != num)
                std::cout << "Cannot remove: Value not found." << std::endl;

            else {
                Node* target = temp->prev;
                target->prev->next = target->next;
                target->next->prev = target->prev;

                if (target == head)
                    head = head->next;
                
                delete target;
                target = nullptr;
                size--;
            }
        }
    }

    void display() {
        Node *temp = head;
        do {
            std::cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }

    int search(int num) {
        Node *temp = head;
        int index = 0;

        while (temp->data != num && temp->next != head) {
            temp = temp->next;
            index++;
        }
        
        return (temp->next == head && temp->data != num) ? -1 : index;
    }

    void searchAll(int num)
    {
        Node* temp = head;
        int index = 0;

        do 
        {
            if (temp->data == num)
            {
                std::cout << index << '\n';
            }
            temp = temp->next;
            index++;
        } while (temp != head);
    }
};

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

int main() {
    CircularLinkedList list;

    list.insert(21);
    list.insert(5);
    list.insert(8);
    list.insert(21);
    list.insert(1);
    list.display();
    list.remove(5);
    list.display();
    list.remove(9);
    list.insert(21);
    list.insert(21);
    list.display();
	// list.remove(8);
	// list.remove(1);

    list.displayBkwd();
    list.searchAll(21);

    return EXIT_SUCCESS;
}