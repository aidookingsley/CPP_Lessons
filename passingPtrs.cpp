#include <iostream>
using namespace std;

double averageCost(double *priceArray, int *count)
{
    double sum = 0;
    for (int i = 0; i < *count; i++)
    {
        sum += *(priceArray + i); // give me the value in the array at that location
    }
    double avg = sum / *count;
    *count += 5;
    cout << "In function count value " << *count << endl;
    return avg;
}
int main()
{
    double prices[5]{5.00, 4.50, 3.75, 3.10, 6.75};
    int quantity = 5;
    cout << "quantity value: " << quantity << endl;
    double average = averageCost(prices, &quantity);
    cout << "$" << average << endl;
    cout << "\nquantity value: " << quantity << endl;

    return 0;
}
