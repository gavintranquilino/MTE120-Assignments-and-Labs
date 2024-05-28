/*some basic operations for the class of linked list*/
#include <iostream>
using namespace std;
typedef int DataType;//defining DataType makes it easier to change int to double in one place for example

struct Node {
    DataType data;
    Node *next;
    Node() : data(0), next(nullptr) {};
    Node(int x) : data(x), next(nullptr) {};// nullptr is a keyword that represents zero as an address. NULL can cause ambiguity in overload function  
};

class LinkedList{
private:
    Node *head; //= nullptr;

public:
    LinkedList(): head(nullptr){};//constructor
    void insert(DataType value, int position);
    void replace(int position, DataType value);
    void remove(int position);
    void reverse(); // reverse the linked list
    Node* search(int target);// return a pointer to the target value
    void print(); // print all elements in the list
};

//Implementation
void LinkedList::insert(DataType value, int position) {
    //step 1. create new node
    Node *newNode = new Node(value);

    //step 2. if special case, when position = 0
    //insert as the new head
    //2.1 when head == nullptr, or size == 0
    if(position == 0){
        if(head == nullptr){
            head = newNode;
            return;
        }
        else{ //2.2 when size > 0
            newNode->next = head;
            head = newNode;
            return;
        }
    }

    //step 3. when position > 0, size > 0
    //iterate through the list to find the position
    //with an additional pointer for the address of the previous node
    Node *previous = head;
    Node *current = head->next;
    int i = 1;
    while (i < position) {
        previous = current;
        current = current->next;
        if (current == nullptr) {
            break; // reach the end
            //if this happens, it means that the position value is larger than it should be
            //by continuing the remaining code in this function,
            //the newNode will be inserted as the tail of the list.
        }
        i++;
    }

    //step 4. insert the node between previous and current
    newNode->next = current;
    previous->next = newNode;
}

void LinkedList::replace(int position, DataType value) {
    //step 1. iterate a pointer to the position
    Node *current = head;
    int i = 0;
    while (i < position) {
        if (current->next == nullptr) {
            break; // reach the end
            //if this happens, it means that the position value is larger than it should be
            //by continuing the remaining code in this function,
            //the value in the tail node of the list will be replaced
        }
        current = current->next;
        i++;
    }

    //step 2. replace the value
    current->data = value;
}

void LinkedList::remove(int position) {
    //step 1. special case, if position == 0, remove head
    if(position == 0){
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        return;
    }

    //step 2. iterate a pointer to the position
    //and another pointer for the node address previous of it
    Node *previous = head;
    Node *current = head->next;
    int i = 1;
    while (i < position) {
        if (current->next == nullptr) {
            break; // reach the end
            //if this happens, it means that the position value is larger than it should be
            //by continuing the remaining code in this function,
            //the node at the tail of the list will be removed
        }
        previous = current;
        current = current->next;
        i++;
    }

    //step 3. remove the node and properly link the remaining nodes.
    previous->next = current->next;
    delete current;
    current = nullptr; 
}

/* Function to reverse the linked list */
void LinkedList::reverse(){
    // Initialize current, previous and next pointers
    Node *current = head;
    Node *previous = nullptr;
    Node *next = nullptr;

    while (current != nullptr) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = previous;
        // Move pointers one position ahead.
        previous = current;
        current = next;
    }
    head = previous;
}

/* function for searching a target value in you linked list*/
Node* LinkedList::search(int target){
    Node* current = nullptr;
    bool found = false;
    current = head; //
    // if target is  not found and we have not completely searched the linked list
    while(!found && current != nullptr){
        if (current->data == target) {
            cout << target << " is in the linked list" << endl;
            found = true;
            return current;
         }    
        current = current->next;
        
    }
    cout << target << " is not in the linked list" << endl;
    return nullptr;
}


void LinkedList::print() {
    //step 1. check if list is empty - you can cout a warning as well
    if (head == nullptr) {
        cout << "head -> NULL" << endl;
        return;
    }

    //step 2. print all nodes
    Node *temp = head;

    while (temp != nullptr) {
        cout<< temp->data << "->";
        temp = temp->next;
    }
    cout<< endl;
}

int main () {
    LinkedList myList;
    // insert values to linked list
    myList.insert(2, 0);
    myList.insert(4, 1);
    myList.insert(1, 0);
    myList.insert(5, 3);
    myList.insert(3, 2);
    myList.print();

    // replace a value
    myList.replace(2, 33);
    myList.print();

    // reverse the linked list
    myList.reverse();
    myList.print();

    // remove values from the linked list based on index
    myList.remove(3);
    myList.remove(0);
    myList.print();

    // search the target value
    Node* target_ptr;
    
    target_ptr = myList.search(100);
    target_ptr = myList.search(1);
    return 0;
}