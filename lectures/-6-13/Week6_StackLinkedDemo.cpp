#include <iostream>
using namespace std;


class Node{
public:
    int data;
    Node *next;

    Node(int x) : data(x), next(nullptr){};
};

class Stack{
private:
    int capacity;  //let's set this capacity constant, since it is linked structure, may just use a vary large number such as max int INT_MAX.
    int size;
    Node *top;  //pointer to the top node

public:
    Stack(int cap);
    ~Stack();

    void push(int x);
    int pop();
    int peek();

    void print();
};

Stack::Stack(int cap): capacity(cap), size(0), top(nullptr){
    //TODO: validate input, e.g., 0 or negative cap.
}

Stack::~Stack(){// properly deallocated dynamic memory in the linked data structure.
    Node *next;
    while(top != nullptr){
        next = top->next;
        delete top;
        top = next;
    }
}

void Stack::push(int x){ //just like InsertFirst in linked List
    //step 1: create a new node to hold x
    Node *newNode = new Node(x);
    //step 2: check if stack is full
    if(size >= capacity){
        cout<<"stack is full! cannot push." <<endl;
        return;
    }
    else{ // step 3: if not full, push node to the top of the list
        //check if top pointer is empty.
        if(top == nullptr){
            top = newNode;
        }else{
            newNode->next = top;
            top = newNode;
        }
        size++;
    }
}

int Stack::pop(){ //like Linked List DeleteFirst and return data
    //Step 1: check if there is anything to pop
    if(size <= 0){ //or top == nullptr
        cout<<"stack is empty! cannot pop." <<endl;
        return -9999;  //EMPTY STACK return constant
    }
    else{//Step 2: if stack not empty, delete the current top node and make the next node the new top node, decrease size and return the data
	Node *returnNode = top;
        top = top->next;

        //may return the data or the node, in this demo, just return the data
        int returnInt = returnNode->data;
        delete returnNode;
        returnNode = nullptr;
        size--;

        return returnInt;
    }
}

int Stack::peek(){ // like SelectFirst in linked list
    //Step 1: check if there is any node
    if(top == nullptr){ //or size <= 0 or size == 0
        cout<<"stack is empty! nothing to peek." <<endl;
        return -9999;  // EMPTY STACK return constant
    }
    else{//Step 2: just return the top value data
        return top->data;
    }
}

void Stack::print(){  //from top to bottom
    //check if there is anything to print
    if(top == nullptr){ //or size <= 0 or size == 0
        cout<<"stack is empty! nothing to print." <<endl;
        return;
    }
    else{
        Node *p = top;
        while(p != nullptr){
            cout<< p->data << endl;
            p = p->next;
        }
        cout<<endl;
    }
}

int main(){
    Stack st1(3);
    Stack *pst2 = new Stack(3);

    cout<<"Test 1: "<<endl;
    cout<<"stack 1: "<<endl;
    st1.print();
    cout<<"stack 2: "<<endl;
    pst2->print();
    cout<<endl;



    cout<<"Test 2: "<<endl;
    st1.push(99);
    st1.push(88);
    st1.push(44);
    st1.push(22); //exceeds capacity

    cout<<"stack 1: "<<endl;
    st1.print();
    cout<<"stack 2: "<<endl;
    pst2->print();
    cout<<endl;




    cout<<"Test 3: "<<endl;
    pst2->push( st1.pop() );
    pst2->push( st1.pop() );
    pst2->push( st1.pop() );

    cout<<"stack 1: "<<endl;
    st1.print();
    cout<<"stack 2: "<<endl;
    pst2->print();
    cout<<endl;




    cout<<"Test 4: "<<endl;
    cout<<st1.pop()<<endl;


    return 0;
}



