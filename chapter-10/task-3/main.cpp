#include <iostream>
#include <string>
using namespace std;

void getNumbers (int table[][10]);

int main()
{
    cout << "Hello, below you can see multiplication Table: " << endl;
    int multiplicationTable [10][10] = { {1,2,3,4,5,6,7,8,9,10},
                           {2}, {3}, {4}, {5}, {6 }, {7}, {8}, {9}, {10}};

    getNumbers(multiplicationTable);

    return 0;
}

void getNumbers (int table[][10])
{
    for (int i=1; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            table [i][j] = table[i][0]*table[0][j];
            cout << table[i][0] << "*"<< table[0][j] << "=" <<  table[i][j] << endl;
        }
    }
}