#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> numbers;
    int temp = 0;

    cout << "Pushing...\n";
    while (temp >= 0)
    {
        cout << "Enter numbers: ";
        cin >> temp;
        if (temp >= 0)
            numbers.push(temp);
    }

    cout << "{ ";
    while (numbers.size() > 0)
    {
        cout << numbers.front();
        numbers.pop();
        cout << " ";
    }
    cout << "}";
    cout << endl;

    return 0;
}
