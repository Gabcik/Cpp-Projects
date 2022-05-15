#include <iostream>
#include <string>
using namespace std;

//char fields [9];

string gamer_1_choice;
string gamer_2_choice;

string respond_to_gamer1_choice(string gamer_1);
void board_to_play(int horizontalDimension, int verticalDimension, char fields[10][10]);
char get_a_sign(int which_player);
void do_move_gamer(int row, int colum, int player, int horizontalDimension, int verticalDimension, char fields[10][10]);

enum Result {
    WIN,
    TIE,
};

Result checkGameResult(int movesCount, int horizontalDimension, int verticalDimension, char fields[10][10]);
void displayGameResult (Result result, int whichPlayer);



int main() {
    char fields [10][10] = { {0,0,0,0,0},  {0,0,0,0,0}};

    cout << "Hello! (:) Cross and circle game (:)" << endl;
    cout << endl << "Choose the size of the board. The dimension cannot be less than 4 or greater than 10." << endl
         << "Horizontal dimension: ";
    int sizeOfHorizontalDimension;
    cin >> sizeOfHorizontalDimension;
    cout << endl << "Vertical dimension: ";
    int sizeOfVerticalDimension;
    cin >> sizeOfVerticalDimension;

    cout << endl << "Gamer 1: cross or circle?" << endl;
    cin >> gamer_1_choice;
    respond_to_gamer1_choice(gamer_1_choice);

    cout << endl << "There is your board to play:" << endl;
    board_to_play(sizeOfHorizontalDimension, sizeOfVerticalDimension, fields);
    cout << "First number means a row. Second number means a column";
    cout << endl << "The winner is the one who puts his mark 4 times in a row";

    for (int sum_all_moves = 0; sum_all_moves < 9; sum_all_moves++) {
        int player = sum_all_moves % 2 + 1;
        int boardRow;
        int boardColumn;

        cout << endl << "Gamer " << player << " move." << endl
            << "Row: ";
        cin >> boardRow;
        cout << " Column: ";
        cin >> boardColumn;
        do_move_gamer(boardRow, boardColumn, player, sizeOfHorizontalDimension, sizeOfVerticalDimension, fields);
        Result result = checkGameResult(sum_all_moves, sizeOfHorizontalDimension, sizeOfVerticalDimension, fields);
        displayGameResult(result, player);
    }
    return 0;
}

string respond_to_gamer1_choice(string gamer_1) {

    do {
        if (gamer_1 != "cross" && gamer_1 != "circle") {
            cout << "Wrong answer, try again. Enter your sign (cross or circle): ";
            cin >> gamer_1;
        }
    } while (gamer_1 != "cross" && gamer_1 != "circle");

    if (gamer_1 == "cross") {
        cout << "Gamer 1 is cross and Gamer 2 is circle";
        return gamer_2_choice = "circle";
    } else if (gamer_1 == "circle") {
        cout << "Gamer 1 is circle and Gamer 2 is cross";
        return gamer_2_choice = "cross";
    }

}

void board_to_play(int horizontalDimension, int verticalDimension, char fields[10][10]) {

    for (int i=0;i<verticalDimension;i++) {
        for (int j = 0; j < horizontalDimension; j++) {
            if (j == 0) {
            cout << " " << "x";
            }
            else if (j == horizontalDimension - 1) {
                cout << " | " << "x" << " " << endl;
            }
            else {
                cout << " | " << "x";
            }
        }
        for (int j = 0; j < horizontalDimension; j++) {
            if (j == 0) {
                cout << "--";
            }
            else if (j == horizontalDimension - 1) {
                cout << "-+---" << endl;
            }
            else {
                cout << "-+--" ;
            }
        }
    }
}

void do_move_gamer(int row, int colum, int player, int horizontalDimension, int verticalDimension, char fields[10][10]) {
    char sign=get_a_sign(player);

    fields[row][colum]=sign;
    board_to_play(horizontalDimension, verticalDimension, fields);
}

char get_a_sign(int which_player) {
    char sign;
    if (which_player == 1) {
        if (gamer_1_choice == "cross") {
            sign = 'x';
        } else {
            sign = 'o';
        }
    }
    else {
        if (gamer_2_choice == "cross") {
            sign = 'x';
        } else {
            sign = 'o';
        }
    }
    return sign;
}

Result checkGameResult (int movesCount, int horizontalDimension, int verticalDimension, char fields[10][10]) {
    char currentSign;
    int sumOfTheSameSigns=0;
    for (int i=0; i<verticalDimension; i++) {
        for (int j=0; j<horizontalDimension-1; j++) {
            currentSign=fields[i][j];
            char nextSign=fields[i][j+1];
            if (currentSign==nextSign) {
                sumOfTheSameSigns++;
            }
            else {
                sumOfTheSameSigns = 0;
            }
            if (sumOfTheSameSigns == 4) {
                return WIN;
            }
        }
    }

    for (int i=0; i<horizontalDimension; i++) {
        for (int j=0; j<verticalDimension-1; j++) {
            currentSign=fields[j][i];
            char nextSign=fields[j+1][i];
            if (currentSign==nextSign) {
                sumOfTheSameSigns++;
            }
            else {
                sumOfTheSameSigns = 0;
            }
            if (sumOfTheSameSigns == 4) {
                return WIN;
            }
        }
    }

    if (movesCount == 9 )
        return TIE;
}

void displayGameResult (Result result, int whichPlayer) {
    switch (result) {
        case WIN:
            cout << endl << "Player " << whichPlayer << " won!";
            break;
        case TIE:
            cout << endl << "We have a tie";
    }
}


