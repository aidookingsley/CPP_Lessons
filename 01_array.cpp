#include <iostream>
using namespace std;
int main()
{
    double values[10];
    double *pValue = values;
    cout << "Value array address: " << values << endl;
    cout << "pvalue: " << pValue << endl;

    int numbers[10];
    int *pNumbers = numbers;
    for (int i = 0; i < 10; i++)
    {
        cout << "numbers address " << i << ": " << pNumbers + i << endl;
    }
    return 0;
}