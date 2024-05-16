#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    cout << "Enter 10 integers: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    cout << "Array elements are: \n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << '\n';
    }
    cout << endl;

    return 0;
}