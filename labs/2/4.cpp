#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* array;
    int capacity;
    int size;

    // Function to resize the array when it reaches capacity
    void resize() {
        // Double the capacity
        int bigCapacity = capacity * 2;

        //Create a new array with the new capacity
        int* biggerAy = new int[bigCapacity];

        // Copy elements from the old array to the new array
        for (int i=0; i<=capacity; i++) 
        {
            biggerAy[i] = array[i];
        }

        // Delete the old array
        delete array;

        // Point to the new array
        array = biggerAy;
    }

public:
    // Constructor to initialize the array with a given capacity
    DynamicArray(int initialCapacity = 10) {
        capacity = initialCapacity;
        size = 0;
        array = new int[capacity];
    }

    // Function to add an element to the array
    void add(int element) {
        if (size == capacity) { // If the array is full, resize it
            resize();
        }
        array[size++] = element; // Add the new element and increment the size
    }

    // Function to display the elements of the array
    void display() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Destructor to clean up the allocated memory
    ~DynamicArray() {
        delete[] array;
    }
};

int main() {
    DynamicArray arr(5);
    for (int i = 0; i < 40; i++) {
        arr.add(i + 1); // Adding elements to the dynamic array
    }
    arr.display(); // Display the elements of the array
    return 0;
}

