#include <iostream>
#include <string>
using namespace std;


int main()
{
    cout << "I count the arithmetic mean of 5 numbers. Enter your numbers: " << endl;
    int fiveNumbers [5];
    cin >> fiveNumbers [0];
    cin >> fiveNumbers [1];
    cin >> fiveNumbers [2];
    cin >> fiveNumbers [3];
    cin >> fiveNumbers [4];

    cout << "Your arithmetic mean is:" << endl
    << "(" << fiveNumbers [0] << "+" << fiveNumbers [1] << "+" << fiveNumbers [2] << "+" << fiveNumbers [3] << "+" << fiveNumbers [4] << ")"
    << "/" << 5 << "=";

    //    getline (cin, fiveNumbers [5]);
    return 0;
}
