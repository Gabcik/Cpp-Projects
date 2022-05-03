#include <iostream>
#include <string>
#include <random>
using namespace std;

int getNumber();
void generateNumbers(int arrayOfNumbers[], int arraySize);
void displayNumbers(int arrayOfNumbers[], int arraySize);
int findTheSmallestElementOfArray (int arrayOfNumbers[], int arraySize);
int findTheLargestElementOfArray (int arrayOfNumbers[], int arraySize);

int main() {
    int randomNumbers [50];
    int sizeOfArray = sizeof(randomNumbers)/sizeof(int);

    generateNumbers(randomNumbers, sizeOfArray);
    cout << endl <<  "Numbers: ";
    displayNumbers(randomNumbers, sizeOfArray);
    int theSmallestElement = findTheSmallestElementOfArray(randomNumbers, sizeOfArray);
    cout << endl << "The smallest element: " << theSmallestElement;
    int theLargestElement= findTheLargestElementOfArray(randomNumbers, sizeOfArray);
    cout << endl << "The largest element: " << theLargestElement;


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

int findTheSmallestElementOfArray (int arrayOfNumbers[], int arraySize) {
    int minimum = arrayOfNumbers[0];
    for (int i=1;i<arraySize;i++) {
        if (minimum > arrayOfNumbers[i]) {
            minimum=arrayOfNumbers[i];
        }
    }
    return minimum;
}

int findTheLargestElementOfArray (int arrayOfNumbers[], int arraySize) {
    int maximum = arrayOfNumbers[0];
    for (int i=1;i<arraySize;i++) {
        if (maximum < arrayOfNumbers[i]) {
            maximum=arrayOfNumbers[i];
        }
    }
    return maximum;
}