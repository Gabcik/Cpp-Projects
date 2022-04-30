#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    int multiplicationTable [10][10] = { {1,2,3,4,5,6,7,8,9,10},
                           {2}, {3}, {4}, {5}, {6 }, {7}, {8}, {9}, {10}};

    for (int i=1; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            multiplicationTable [i][j] = multiplicationTable[i][0]*multiplicationTable[0][j];
            cout << multiplicationTable[i][0] << "*"<< multiplicationTable[0][j] << "=" <<  multiplicationTable[i][j] << endl;
        }
    }

    return 0;

}

