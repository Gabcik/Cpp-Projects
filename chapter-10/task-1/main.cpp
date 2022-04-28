#include <iostream>
#include <string>
using namespace std;

float arithmeticMean (float sumOfNumbers);

float fiveNumbers [5];

int main()
{
    cout << "I count the arithmetic mean of 5 numbers. Enter your numbers: " << endl;

    float sumOfNumbers;
    for (int i = 0; i<5; i++)
    {
        cin >> fiveNumbers[i];
        sumOfNumbers+=fiveNumbers[i];
    }

    cout << "Your arithmetic mean is:" << endl
    << "(" << fiveNumbers [0] << "+" << fiveNumbers [1] << "+" << fiveNumbers [2] << "+" << fiveNumbers [3] << "+" << fiveNumbers [4] << ")"
    << "/" << 5 << "=" << arithmeticMean(sumOfNumbers);

//    cout << endl << "give me all values from array" << fiveNumbers [5];

    //    getline (cin, fiveNumbers [5]);
    return 0;
}

float arithmeticMean (float sumOfNumbers)
{
    float arithmeticMean = sumOfNumbers/5;
    return arithmeticMean;
}
