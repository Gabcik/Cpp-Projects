#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
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

int main() {
    cout << "ONE-ARMED BANDIT" << endl
    << "Pay 50 zl to play." << endl;

//    int declarationToPlay;
//    cin >> declarationToPlay;
    cout << "It's board: " << endl;
    getBoard();
    cout << endl <<  "On the board I can display you symbols: # | % | @ "
        << endl << "To win you must draw 3 the same symbols on the board.";
    getNumber();
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

int getNumber ()
{
    srand(time (NULL));
    int number = rand ()%3+1;
    char symbol = getSymbol(number);
    cout << "symbol: " << symbol;
    return symbol;
}