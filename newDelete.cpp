#include <iostream>
using namespace std;

int main()
{
    int *pointer(new int(55));
    cout << *pointer << endl;
    delete pointer;

    int *pArray(new int[5]{10, 20, 30, 40, 50});
    *(pArray + 1) += 5;
    cout << *pArray << ", " << *(pArray + 1) << endl;
    delete[] pArray;

    return 0;
}