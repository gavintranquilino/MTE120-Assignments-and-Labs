#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE + 1];
    int n;

    cout << "Enter 10 integers: ";
    for (n = 0; n < SIZE; n++) {
        cin >> arr[n];
    }

    int element, position;
    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the position to insert (0 to " << n << "): ";
    cin >> position;

    if (position < 0 || position > n) {
        cout << "Position can't be negative or above size"; // provide a warning sign
        return 1; // leave the code
    }

    for (int i = n; i > position; i--) {
        arr[i] = arr[i-1]; //traverse through the code from i index to i-1
    }
    arr[position] = element;
    n++;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}