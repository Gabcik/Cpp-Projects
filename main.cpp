#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

char field1 ='1';
char field2 ='1';
char field3 ='1';
char field4 ='1';
char field5 ='1';
char field6 ='1';
char field7 ='1';
char field8 ='1';
char field9 ='1';


string getBoard ();
int getNumber ();
char getSymbol (int number);
char putSymbolOnBoard (char symbol);

int main() {
    cout << "ONE-ARMED BANDIT" << endl
    << "Pay 50 zl to play." << endl;

//    int declarationToPlay;
//    cin >> declarationToPlay;
    cout << "It's board: " << endl;
    getBoard();
    cout << endl <<  "On the board I can display you symbols: # | % | @ "
        << endl << "To win you must draw 3 the same symbols on the board." << endl;

    for (int i=1; i<=9; i++)
    {
        char symbol = getSymbol(getNumber());
        putSymbolOnBoard(symbol);
    }
    getBoard();
    return 0;
}

string getBoard ()
{
    cout << "| " << field1 << " || " << field2 << " || " << field3 << " |" << endl
         << "|---||---||---|" << endl
         << "| " << field4 << " || " << field5 << " || " << field6 << " |" << endl
         << "|---||---||---|" << endl
         << "| " << field7 << " || " << field8 << " || " << field9 << " |";
}

int getNumber ()
{
    struct timespec tm;
    clock_gettime(CLOCK_MONOTONIC, &tm);
    int number = rand ()%3+1;
    return number;
}

char getSymbol (int number)
{
    char symbol;
    switch (number)
    {
        case 1:
        {
            return symbol = '#';
            break;
        }
        case 2:
        {
            return symbol = '%';
            break;
        }
        case 3:
        {
            return symbol = '@';
            break;
        }
    }
}

char putSymbolOnBoard (char symbol)
{
    if (field1=='1')
    {
        field1 = symbol;
    }
    else if (field2=='1' && field1 !='1')
    {
        field2 = symbol;
    }
    else if (field3=='1' && field1!='1' && field2!='1')
    {
        field3 = symbol;
    }
    else if (field4=='1' && field1!='1' && field2!='1' && field3!='1')
    {
        field4 = symbol;
    }
    else if (field5=='1' && field1!='1' && field2!='1' && field3!='1' && field4!='1')
    {
        field5 = symbol;
    }
    else if (field6=='1' && field1!='1' && field2!='1' && field3!='1' && field4!='1' && field5!='1')
    {
        field6 = symbol;
    }
    else if (field7=='1' && field1!='1' && field2!='1' && field3!='1' && field4!='1' && field5!='1' && field6!='1')
    {
        field7 = symbol;
    }
    else if (field8=='1' && field1!='1' && field2!='1' && field3!='1' && field4!='1' && field5!='1' && field6!='1' && field7!='1')
    {
        field8 = symbol;
    }
    else
    {
        field9 = symbol;
    }
}
