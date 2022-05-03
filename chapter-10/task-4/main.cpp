#include <iostream>
#include <string>
#include <random>
using namespace std;

int getNumber();
void generateNumbers(int arrayOfNumbers[], int arraySize);
void displayNumbers(int arrayOfNumbers[], int arraySize);
void sortNumbers (int arrayOfNumbers[], int arraySize);

int main() {
    int randomNumbers [15];
    int sizeOfArray = sizeof(randomNumbers)/sizeof(int);

    generateNumbers(randomNumbers, sizeOfArray);
    displayNumbers(randomNumbers, sizeOfArray);
    sortNumbers(randomNumbers, sizeOfArray);
    cout << endl <<  "Sorted numbers: ";
    displayNumbers(randomNumbers, sizeOfArray);

    return 0;
}

void generateNumbers(int arrayOfNumbers[], int arraySize){
    for (int i=0;i<arraySize;i++) {
        int number = getNumber();
        arrayOfNumbers[i]=number;
    }
}

int getNumber(){
    random_device device;
    std::mt19937 generator(device());
    uniform_int_distribution<int> distribution(1,50);
    return distribution(device);
}

void displayNumbers(int arrayOfNumbers[], int arraySize) {
    for (int i=0;i<arraySize;i++) {
        cout << arrayOfNumbers[i] << " ";
    }
}

void sortNumbers (int arrayOfNumbers[], int arraySize) {
    int temp=0;
    for (int i=0;i<arraySize;i++) {
        for (int j=i+1;j<arraySize;j++) {
            if (arrayOfNumbers[j]<arrayOfNumbers[i]) {
                temp = arrayOfNumbers[i];
                arrayOfNumbers[i]=arrayOfNumbers[j];
                arrayOfNumbers[j]=temp;
            }
        }
    }
}
