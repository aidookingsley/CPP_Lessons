#include <iostream>

int main()
{
    int number = 240;
    int *numPtr;
    numPtr = &number;
    std::cout << "The address of number is: " << numPtr << "\n";
    return 0;
}