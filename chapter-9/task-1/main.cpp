#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>

using namespace std;

#pragma execution_character_set( "utf-8" )

void divideNumberBasedOn0 (int number);
void uniqueNumbers1to19and100 (int number);
void identifyingDecimalNumbers (int number);
void identifyingSingularNumber (int number, int decimalNumber);


int main()
{
    SetConsoleOutputCP( 65001 );

    int userNumber;
    do {
        cout << endl <<  "Enter the number in range of -100 to 100 to continue or enter number more than 100 or less than -100 to end me.\n";
        cin >> userNumber;
        divideNumberBasedOn0(userNumber);
        uniqueNumbers1to19and100 (userNumber);
        if ((userNumber >=20 && userNumber<100) || userNumber <=-20 && userNumber>-100)
        {
            identifyingDecimalNumbers(userNumber);
        }
    } while (userNumber>-101 && userNumber <101);

}

void divideNumberBasedOn0 (int number)
{
    if (number<0 && number >=-100)
    {
        cout << "minus ";
    }
    if (number==0)
    {
        cout << "zero ";
    }
    if (number>0 && number<=100)
    {
        cout << "plus ";
    }
}

void uniqueNumbers1to19and100 (int number)
{
    if (number <0)
    {
        number=number*(-1);
    }

    switch (number)
    {
        case 1:
            cout << "jeden";
            break;
        case 2:
            cout << "dwa";
            break;
        case 3:
            cout << "trzy";
            break;
        case 4:
            cout << "cztery";
            break;
        case 5:
            cout << "piec";
            break;
        case 6:
            cout << "sześć";
            break;
        case 7:
            cout << "siedem";
            break;
        case 8:
            cout << "osiem";
            break;
        case 9:
            cout << "dziewięć";
            break;
        case 10:
            cout << "dziesięć";
            break;
        case 11:
            cout << "jedenaście";
            break;
        case 12:
            cout << "dwanaście";
            break;
        case 13:
            cout << "trzynaście";
            break;
        case 14:
            cout << "czternaście";
            break;
        case 15:
            cout << "piętnaście";
            break;
        case 16:
            cout << "szesnaście";
            break;
        case 17:
            cout << "siedemnaście";
            break;
        case 18:
            cout << "osiemnaście";
            break;
        case 19:
            cout << "dziewiętnaście";
            break;
        case 100:
            cout << "sto";
            break;
    }
}


void identifyingDecimalNumbers (int number)
{
    if (number<0)
    {
        number=number*(-1);
    }

    int whichDecimalNumber;
    whichDecimalNumber=number/10;

            if (whichDecimalNumber==2)
            {
                uniqueNumbers1to19and100(whichDecimalNumber);
                cout << "dzieścia";
            }
    if (whichDecimalNumber==3 || whichDecimalNumber ==4)
    {
        uniqueNumbers1to19and100(whichDecimalNumber);
        cout  << "dzieści";
    }
    if (whichDecimalNumber>4)
    {
        uniqueNumbers1to19and100(whichDecimalNumber);
        cout << "dziesiąt";
    }
    identifyingSingularNumber(number, whichDecimalNumber);

}

void identifyingSingularNumber (int number, int decimalNumber)
{
        int singularNumber = number - decimalNumber * 10;
        uniqueNumbers1to19and100(singularNumber);
}

