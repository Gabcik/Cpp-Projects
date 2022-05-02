#include <iostream>
#include <string>
#include <random>
using namespace std;

int getNumber();
void generate10Numbers(int arrayOfNumbers[]);
void sortNumbers (int previousNumber, int currentNumber, int index, int arrayOfNumbers[]);

int main() {
    int randomNumbers [10];
    generate10Numbers(randomNumbers);

    printf ("%d %d %d %d %d %d %d %d %d %d", randomNumbers[0],randomNumbers[1], randomNumbers[2], randomNumbers[3], randomNumbers[4], randomNumbers[5], randomNumbers[6], randomNumbers[7], randomNumbers[8], randomNumbers[9]);
    return 0;
}

int getNumber(){
    random_device device;
//    std::mt19937 generator(device());
    uniform_int_distribution<int> distribution(1,20);
    return distribution(device);
}

void generate10Numbers(int arrayOfNumbers[]){
    int previousNumber;
    for (int i=0;i<10;i++){
        int number = getNumber();
        arrayOfNumbers[i]=number;
        if (i>0){
            sortNumbers(previousNumber, number, i, arrayOfNumbers);
        }
        previousNumber = number;
    }
}

void sortNumbers (int previousNumber, int currentNumber, int index, int arrayOfNumbers[]) {
    if (currentNumber<previousNumber) {
        arrayOfNumbers[index-1]=currentNumber;
        arrayOfNumbers[index]=previousNumber;
    }
}