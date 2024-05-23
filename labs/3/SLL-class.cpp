/*
Implementing a singly linked list with functions only. The list of functions in this __file__ includes:
1. void insert(head, value, position) --> To insert nodes into the singly linked list (SLL) at the specified position. 
2. void remove(head, position)        --> To remove a node given the position of the Node. 
3. Node* search(head, target)         --> To search for a Node given its value 
4. void reverse(head)                 --> To reverse a SLL 
5. void replace(head, value, position) --> To replace the value of a node, given where it is present. 
6. void print(head)                    --> To print the results. 
*/


#include<iostream>
using namespace std; 

struct Node{
    int data;
    Node *next; 
};


void insert(Node *&head, int value, int position) {
    //step 1. create new node
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

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
    while (i < position && previous->next != nullptr) { //To check if position doesn't exceed the size of the linked list
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

void remove(Node *&head, int position) {
    //step 1. special case, if position == 0, remove head
    if(position == 0 && head!=nullptr){
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

Node* search(Node *head, int target){
    Node* current = nullptr;
    bool found = false;
    current = head; //
    int pos_counter = 0;
    // if target is  not found and we have not completely searched the linked list
    while(!found && current != nullptr){
        if (current->data == target) {
            cout << target << " is in the linked list at position: "<< pos_counter << endl;
            found = true;
            return current;
         }    
        current = current->next;
        pos_counter+=1;
        
    }
    cout << target << " is not in the linked list" << endl;
    return nullptr;
}

void reverse(Node *&head){
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

void replace(Node *&head, int position, int value) {
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

void print(Node *&head) {
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


int main(){

    Node *head = nullptr; 
    //head->next = nullptr;

    insert(head, 10, 0); //{head, value, position} 
    print(head);


    return 0;
}

