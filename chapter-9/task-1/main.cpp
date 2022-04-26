#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>

using namespace std;

#pragma execution_character_set( "utf-8" )

void divideNumberBasedOn0 (int number);
string uniqueNumbers1to19 (int number);
void identifyingDecimalNumbers (int number);
void identifyingSingularNumber (int number, int decimalNumber);


int main()
{
    SetConsoleOutputCP( 65001 );
    cout << "Enter the number in range of -100 to 100. I will present the number in the form of words." << endl;
    int userNumber;

    do {
        cin >> userNumber;
        divideNumberBasedOn0(userNumber);
        uniqueNumbers1to19(userNumber);
        identifyingDecimalNumbers(userNumber);
        cout << endl <<  "Enter the number in range of -100 to 100 to continue or >100 to end me.";
    } while (userNumber <=100);

}

void divideNumberBasedOn0 (int number)
{
    if (number<0)
    {
        cout << "minus ";
    }
    if (number==0)
    {
        cout << "zero ";
    }
    if (number>0)
    {
        cout << "plus ";
    }
}

string uniqueNumbers1to19 (int number)
{
    string numberInWord;
    if ( number==1)
    {
        cout << "jeden";
        return numberInWord = "jeden";
    }
    if ( number==2)
    {
        cout << "dwa";
        return numberInWord = "dwa";
    }
    if ( number==3)
    {
        cout << "trzy";
        return numberInWord = "trzy";
    }if ( number==4)
    {
        cout << "cztery";
        return numberInWord = "cztery";
    }if ( number==5)
    {
        cout << "pięć";
        return numberInWord = "pięć";
    }
    if ( number==6)
    {
        cout << "sześć";
        return numberInWord = "osiem";
    }if ( number==7)
    {
        cout << "siedem";
        return numberInWord = "osiem";
    }if ( number==8)
    {
        cout << "osiem";
        return numberInWord = "osiem";
    }if ( number==9)
    {
        cout << "dziewięć";
        return numberInWord = "dziewięć";
    }if ( number==10)
    {
        cout << "dziesięć";
        return numberInWord = "dziesięć";
    }if ( number==11)
    {
        cout << "jedynaście";
        return numberInWord = "jedynaście";
    }if ( number==12)
    {
        cout << "dwanaście";
        return numberInWord = "dwanaście";
    }if ( number==13)
    {
        cout << "trzynaście";
        return numberInWord = "trzynaście";
    }
    if ( number==14)
    {
        cout << "czternaście";
        return numberInWord = "czternaście";
    }if ( number==15)
    {
        cout << "piętnaście";
        return numberInWord = "piętnaście";
    }if ( number==16)
    {
        cout << "szesnaście";
        return numberInWord = "siedemnaście";
    }if ( number==17)
    {
        cout << "siedemnaście";
        return numberInWord = "siedemnaście";
    }if ( number==18)
    {
        cout << "osiemnaście";
        return numberInWord = "osiemnaście";
    }if ( number==19)
    {
        cout << "dziewiętnaście";
        return numberInWord = "dziewiętnaście";
    }
}

void identifyingDecimalNumbers (int number)
{
    int whichDecimalNumber;
    if (number<0)
    {
        whichDecimalNumber= (number/10)*(-1);
    }
    else
    {
        whichDecimalNumber = number/10;
    }

    string firstPartOfNumber = uniqueNumbers1to19(whichDecimalNumber);
            if (whichDecimalNumber==2)
            {
                cout << firstPartOfNumber << "dzieścia";
            }
    if (whichDecimalNumber==3 || whichDecimalNumber ==4)
    {
        cout << firstPartOfNumber << "dzieści";
    }
    if (whichDecimalNumber>4)
    {
        cout << firstPartOfNumber << "dziesiąt";
    }
    identifyingSingularNumber(number, whichDecimalNumber);

}

void identifyingSingularNumber (int number, int decimalNumber)
{
    int singularNumber=number-decimalNumber*10;
    string singularNumberInWord = uniqueNumbers1to19(singularNumber);
    cout << singularNumberInWord;
}

