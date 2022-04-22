#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <random>

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


void drawBoard ();
void showUsersOption ();
int respondToUserDecision (int userDecision);
int checkWinningConfiguration ();
void respondToWinningConfiguration (int winningPrice);
int moneyOperations (int userDecision, int currentSaldo, int payed, int prize);
string whetherContinueTheGame(int userDecision);
int getNumber ();
char getSymbol (int number);
void putSymbolOnBoard (char symbol, int sumOfLoop);
void doPull ();
int handleWithNoUserDeposit (int userMoney);

enum decision
{
    PULL = 1,
    DEPOSIT_MONEY,
    END
};
int prize;

int main() {
    cout << "ONE-ARMED BANDIT" << endl
    << "Pay 50 zl to play." << endl;

    int userMoney = 10;
    cout << "Your current saldo is " << userMoney << " PLN" <<  endl;

    cout << "It's board: " << endl;
    drawBoard();
    cout << endl <<  "On the board I can display you symbols: # | % | @ "
        << endl << "To win you must draw 3 the same symbols vertically or across on the board.";

    int userDecision;
    string continueGame;
    do
    {
        showUsersOption();
        cin >> userDecision;
        int payedMoney=respondToUserDecision(userDecision);
        userMoney = moneyOperations (userDecision, userMoney, payedMoney, prize);
        cout << endl << "Your current saldo is " << userMoney << endl;
        if (userMoney == 0)
        {
            payedMoney=handleWithNoUserDeposit(userMoney);
            userMoney = moneyOperations (userDecision, userMoney, payedMoney, prize);
        }
        continueGame=whetherContinueTheGame(userDecision);
    } while (continueGame == "yes" && userMoney > 0);

    if (userMoney == 0)
    {
        cout << endl << "You must deposit money to pull again!"
        << endl << "Available options: 2. deposit money 3. end"
        << endl << "My choice is: ";
        cin >> userDecision;
        respondToUserDecision(userDecision);
    }

}

void drawBoard ()
{
    cout << "| " << field1 << " || " << field2 << " || " << field3 << " |" << endl
         << "|---||---||---|" << endl
         << "| " << field4 << " || " << field5 << " || " << field6 << " |" << endl
         << "|---||---||---|" << endl
         << "| " << field7 << " || " << field8 << " || " << field9 << " |";
}

void showUsersOption ()
{
    cout << endl << "Available options:" << endl <<  "1. pull" << endl << "2. deposit money" << endl << "3. end"
         << endl << "My choice is ";
}

int respondToUserDecision (int userDecision)
{
    int payedMoney = 0;

    switch (userDecision)
    {
        case PULL:
        {
            doPull();
            break;
        }
        case DEPOSIT_MONEY:
        {
            cout << "I'm paying";
            cin >> payedMoney;
            doPull();
            break;
        }
        case END:
        {
            cout << "Thank you for game :)";
            break;
        }
    }

    return payedMoney;

}

void doPull ()
{
    for (int i = 1; i <= 9; i++) {
        char symbol = getSymbol(getNumber());
        putSymbolOnBoard(symbol, i);
    }
    drawBoard();

    prize = checkWinningConfiguration ();
    respondToWinningConfiguration(prize);
}

int getNumber ()
{
    random_device device;
//    std::mt19937 generator(device());
    uniform_int_distribution<int> distribution(1,3);
    return distribution(device);
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

void putSymbolOnBoard (char symbol, int sumOfLoop)
{
    if (sumOfLoop == 1)
    {
        field1 = symbol;
    }
    else if (sumOfLoop == 2)
    {
        field2 = symbol;
    }
    else if (sumOfLoop == 3)
    {
        field3 = symbol;
    }
    else if (sumOfLoop == 4)
    {
        field4 = symbol;
    }
    else if (sumOfLoop == 5)
    {
        field5 = symbol;
    }
    else if (sumOfLoop == 6)
    {
        field6 = symbol;
    }
    else if (sumOfLoop == 7)
    {
        field7 = symbol;
    }
    else if (sumOfLoop == 8)
    {
        field8 = symbol;
    }
    else
    {
        field9 = symbol;
    }
}


int checkWinningConfiguration ()
{
    int prize = 0;
    int sumOfPrize = 0;
    if (field1 == '#' && field2 == '#' && field3 == '#')
        {
            prize = 50;
            sumOfPrize=sumOfPrize+prize;
        }
    if (field4 == '#' && field5 == '#' && field6 == '#')
        {
            prize = 50;
            sumOfPrize=sumOfPrize+prize;
        }

    if (field7 == '#' && field8 == '#' && field9 == '#')
        {
            prize = 50;
            sumOfPrize=sumOfPrize+prize;
        }
    if (field1 == '%' && field2 == '%' && field3 == '%')
        {
            prize = 50;
            sumOfPrize=sumOfPrize+prize;
        }
    if (field4 == '%' && field5 == '%' && field6 == '%')
        {
            prize = 50;
            sumOfPrize=sumOfPrize+prize;
        }

    if (field7 == '%' && field8 == '%' && field9 == '%')
        {
            prize = 50;
            sumOfPrize=sumOfPrize+prize;
        }
    if (field1 == '@' && field2 == '@' && field3 == '@')
        {
            prize = 50;
            sumOfPrize=sumOfPrize+prize;
        }
    if (field4 == '@' && field5 == '@' && field6 == '@')
        {
            prize = 50;
            sumOfPrize=sumOfPrize+prize;
        }

    if (field7 == '@' && field8 == '@' && field9 == '@')
        {
            prize = 50;
            sumOfPrize=sumOfPrize+prize;
        }


    if (field1 == '#' && field5 == '#' && field9 == '#')
        {
            prize = 100;
            sumOfPrize=sumOfPrize+prize;
        }
    if (field3 == '#' && field5 == '#' && field7 == '#')
        {
            prize = 100;
            sumOfPrize=sumOfPrize+prize;
        }
    if (field1 == '%' && field5 == '%' && field9 == '%')
        {
            prize = 100;
            sumOfPrize=sumOfPrize+prize;
        }
    if (field3 == '%' && field5 == '%' && field7 == '%')
        {
            prize = 100;
            sumOfPrize=sumOfPrize+prize;
        }
    if (field1 == '@' && field5 == '@' && field9 == '@')
        {
            prize = 100;
            sumOfPrize=sumOfPrize+prize;
        }
    if (field3 == '@' && field5 == '@' && field7 == '@')
        {
            prize = 100;
            sumOfPrize=sumOfPrize+prize;
        }

    return sumOfPrize;
}

void respondToWinningConfiguration (int winningPrice)
{
    switch (winningPrice)
    {
        case 50:
        {
            cout << endl << "You won! The price is " << winningPrice << "PLN" << endl;
            break;
        }
        case 100:
        {
            cout << endl << "You won! The price is " << winningPrice << "PLN" << endl;
            break;
        }
    }
}

int moneyOperations (int userDecision, int currentSaldo, int payed, int prize)
{
    if (userDecision == PULL)
        {
            return currentSaldo=currentSaldo-10+prize;
        }
    else if (userDecision == DEPOSIT_MONEY)
        {
            return currentSaldo=currentSaldo+payed;
        }
}

int handleWithNoUserDeposit (int userMoney)
{
        int userDecision;
        cout << endl << "You must deposit money to pull again!"
             << endl << "Available options: 2. deposit money 3. end"
             << endl << "My choice is: ";
        cin >> userDecision;
        int payedMoney = respondToUserDecision(userDecision);
        return payedMoney;
}

string whetherContinueTheGame(int userDecision)
{
    string continueTheGame;
    if (userDecision == PULL || userDecision == DEPOSIT_MONEY)
    {
        return continueTheGame = "yes";
    }
    else if (userDecision == END)
    {
        return continueTheGame = "no";
    }
}