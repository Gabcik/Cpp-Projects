#include <iostream>
#include <string>
using namespace std;

char fields [9];

string gamer_1_choice;
string gamer_2_choice;

string respond_to_gamer1_choice(string gamer_1);
void board_to_play();
char get_a_sign(int which_player);
void do_move_gamer(int chosen_move_gamer, int player);

enum Result {
    WIN,
    TIE,
};

Result checkGameResult();
void displayGameResult (Result result, int whichPlayer);



int main() {

    cout << "Hello! (:) Cross and circle game (:)" << endl;
    cout << "Gamer 1: cross or circle?" << endl;
    cin >> gamer_1_choice;
    respond_to_gamer1_choice(gamer_1_choice);

    cout << endl << "below you see the board to play with numbered fields (from 1 to 9): " << endl << endl;
    board_to_play();

    for (int sum_all_moves = 0; sum_all_moves < 9; sum_all_moves++) {
        int player = sum_all_moves % 2 + 1;
        int chosen_move_gamer;

        cout << endl << "Gamer " << player << " move: ";
        cin >> chosen_move_gamer;
        do_move_gamer(chosen_move_gamer, player);
        Result result = checkGameResult();
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

void board_to_play() {
    for (int i=0;i<9;i+=3) {
        cout << " " << fields[i] << " | " << fields[i+1] << " | " << fields[i+2] << " " << endl;
        // dodaj ze przy ostatnim obrocie pętli bez cout ponizej
        cout << "---+---+---" << endl;
    }
}

void do_move_gamer(int chosen_move_gamer, int player) {
    char sign=get_a_sign(player);

    fields[chosen_move_gamer-1]=sign;
    board_to_play();
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

Result checkGameResult () {
    int i=0;

    for (i=0;i<3;i++) {
        if (fields[i] == fields[i + 3] && fields[i + 3] == fields[i + 6])
            return WIN;
    }

    for (i=0;i<7;i+=3) {
        if (fields[i] == fields[i+1] == fields[i+2])
            return WIN;
    }

    if (fields[2] == fields[4] && fields[4] == fields[6]
        || fields[0] == fields [4] && fields[4] == fields[8])
            return WIN;
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


