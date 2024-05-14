#include <iostream>

int main()
{
    int a = 1;
    int *b = &a;

    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n'; // data not actually stored as hexadecimal
    std::cout << "*b: " << *b << '\n';
    
    double *c = new double(3.14);

    std::cout << "c: " << c << '\n';
    std::cout << "*c: " << *c << '\n';

    // bruh



    return 0;
}