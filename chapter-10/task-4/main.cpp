#include <iostream>
#include <string>
#include <random>
using namespace std;

int getNumber();
void generate10Numbers(int arrayOfNumbers[]);
void displayNumbers(int arrayOfNumbers[]);
void sortNumbers (int arrayOfNumbers[]);

int main() {
    int randomNumbers [10];
    generate10Numbers(randomNumbers);
    displayNumbers(randomNumbers);
    sortNumbers(randomNumbers);
    cout << endl <<  "Sorted numbers: ";
    displayNumbers(randomNumbers);

    return 0;
}

void generate10Numbers(int arrayOfNumbers[]){
    for (int i=0;i<10;i++) {
        int number = getNumber();
        arrayOfNumbers[i]=number;
    }
}

int getNumber(){
    random_device device;
//    std::mt19937 generator(device());
    uniform_int_distribution<int> distribution(1,20);
    return distribution(device);
}

void displayNumbers(int arrayOfNumbers[]) {
    for (int i=0;i<10;i++) {
        cout << arrayOfNumbers[i] << " ";
    }
}

void sortNumbers (int arrayOfNumbers[]) {
    int temp=0;
    for (int i=0;i<10;i++) {
        for (int j=i+1;j<10;j++) {
            if (arrayOfNumbers[j]<arrayOfNumbers[i]) {
                temp = arrayOfNumbers[i];
                arrayOfNumbers[i]=arrayOfNumbers[j];
                arrayOfNumbers[j]=temp;
            }
        }
    }
}
