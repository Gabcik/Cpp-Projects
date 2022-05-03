#include <iostream>
#include <string>
using namespace std;

string checkIfSorted (int arrayOfNumbers[]);

int main() {
    int numbers [] = {1,2,3,4,5,11,7,8,9,10};
    string answerIfSorted = checkIfSorted(numbers);
    cout << "The numbers are sorted: " << answerIfSorted << endl;
    return 0;
}

string checkIfSorted (int arrayOfNumbers[]) {
    string response;
    for (int i = 0; i < 9; i++) {
        if (arrayOfNumbers[i] < arrayOfNumbers[i + 1]) {
            response = "true";
        }
        else {
            response = "false";
            break;
        }
    }

    return response;
}
