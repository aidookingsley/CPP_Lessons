#include <iostream>
using namespace std;

int main()
{
    // int num = 10;
    // int *pNum = &num;
    // int **p2Num = &pNum;

    // cout << "Address of num: " << &num << endl;
    // cout << "Address stored in pNum: " << pNum << endl;
    // cout << "Address of pNum: " << &pNum << endl;
    // cout << "Address stored in p2Num: " << p2Num << endl;

    int testScores[5]{100, 95, 99, 85, 83};
    int *pointerArray[5];
    for (int i = 0; i < 5; ++i)
    {
        pointerArray[i] = &(testScores[i]);
        cout << **(pointerArray + i) << endl; // value at address
        cout << *(pointerArray + i) << endl;  // address
        cout << *(pointerArray[i]) << endl;   // value at address
        cout << pointerArray << endl;         // points 1st address
        cout << pointerArray[i] << endl;      // address
    }
    return 0;
}