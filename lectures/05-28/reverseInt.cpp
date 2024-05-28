#include <iostream>

void reverse(int num)
{
    if (num == 0)
    {
        return;
    }
    else
    {
        std::cout << num % 10;
        reverse(num / 10);
    }
}


int main()
{
    reverse(123);
}