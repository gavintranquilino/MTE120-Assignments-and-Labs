#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    int n;

    cout << "Enter 10 integers: ";
    for (n = 0; n < SIZE; n++) {
        cin >> arr[n];
    }

    int position;
    cout << "Enter the position to delete (0 to " << n-1 << "): ";
    cin >> position;

    if (position < 0 || position >= n) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    for (int i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}