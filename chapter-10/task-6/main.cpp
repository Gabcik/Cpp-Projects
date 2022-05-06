#include <iostream>
#include <string>
using namespace std;

bool checkIfSorted (int arrayOfNumbers[]);

int main() {
    int numbers [] = {0,2,3,4,5,6,7,7,9,10};
    bool answerIfSorted = checkIfSorted(numbers);
    cout << "The numbers are sorted: " << std::boolalpha << answerIfSorted << endl;
    return 0;
}

bool checkIfSorted (int arrayOfNumbers[]) {
    bool response;
    for (int i = 0; i < 9; i++) {
        if (arrayOfNumbers[i] < arrayOfNumbers[i + 1]) {
            response = true;
        }
        else {
            response = false;
            break;
        }
    }

    return response;
}
