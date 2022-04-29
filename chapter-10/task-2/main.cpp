#include <iostream>
#include <string>
using namespace std;

int main() {

    cout << "Below you can see Fibonacci sequence:" << endl;

    int fibonacciSequence [20];
    fibonacciSequence[0]=1;
    fibonacciSequence[1]=1;

    cout << "number 1: " << fibonacciSequence[0] << endl;
    cout << "number 2: " << fibonacciSequence [1] << endl;
    for (int i=2 ; i<20; i++)
    {
        fibonacciSequence[i]=fibonacciSequence[i-2]+fibonacciSequence[i-1];
        cout << "number " << i << " : " << fibonacciSequence [i] << endl;
    }
    return 0;
}
