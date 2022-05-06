#include <iostream>
#include <string>
using namespace std;

char fields [3][3];

string gamer_1_choice;
string gamer_2_choice;

string respond_to_gamer1_choice(string gamer_1);
void board_to_play();
char get_a_sign(int which_player);
void do_move_gamer(int chosen_move_gamer, int player);

enum Result {
    WIN,
    TIE,
    LOSE
};

Result checkGameResult();
void displayGameResult (Result result);



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
        displayGameResult(result);
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
    for (int i=0;i<3;i++) {
        cout << " " << fields[i][i] << " | " << fields[i][i+1] << " | " << fields[i][i+2] << " " << endl;
        // dodaj ze przy ostatnim obrocie pętli bez cout ponizej
        cout << "---+---+---" << endl;
    }
}

void do_move_gamer(int chosen_move_gamer, int player) {
    char sign=get_a_sign(player);

    switch (chosen_move_gamer) {
        case 1:
        fields[0][0] = sign;
        break;
        case 2:
        fields[0][1] = sign;
        break;
        case 3:
        fields[0][2] = sign;
        break;
        case 4:
        fields[1][0] = sign;
        break;
        case 5:
        fields[1][1] = sign;
        break;
        case 6:
        fields[1][2] = sign;
        break;
        case 7:
        fields[2][0] = sign;
        break;
        case 8:
        fields[2][1] = sign;
        break;
        case 9:
        fields[2][2] = sign;
        break;
        default:
        cout << "no correct choice";
    }
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

int checkGameResult () {

    for (int i=0;i<3;i++) {
        if (fields[i][0]==fields[i][1] && fields[i][1]==fields[i][2]) {
            return WIN;
        }
        else if (fields[0][i]==fields[1][i] && fields[1][i]==fields[2][i]) {
            return WIN;
        }
        else if ( (fields[i][0]==fields[i+1][1] && fields[i+1][1]==fields[i+2][2])
                ||(fields[i][2]==fields[i+1][1] && fields[i+1][1] == fields [i+2][0]) ) {
            return WIN;
        }
        else {
            return LOSE;
        }
    }
}

void displayGameResult (bool result) {
    if result = 1
}


