#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <unordered_map>
#include <sstream>
#include <unistd.h>
#include <algorithm>
#include <limits>

using namespace std;

void q1a(int &length, int * arrPointer){
    cout << " Please enter the length of the array " << endl;
    cin >> length;

    arrPointer = new int[length];

    for (int i = 0; i < length; i++){
        cout << "Enter an element for the array" << endl;
        cin >> arrPointer[i];
    }

    for (int i = 0; i < length; i++){
        cout << arrPointer[i] << endl;
    }

    delete[] arrPointer;
}

void q1b(int &length, int * pArr){
    cout << "Please enter the length of the array: " << endl;
    cin >> length;

    pArr = new int[length];

    for (int i = 0; i < length; i++){
        cout << "Please enter an element of the array" << endl;
        cin >> pArr[i];
    }

    for (int i = length - 1; i > -1; i--){
        cout << pArr[i] << endl;
    }

    delete[] pArr;
}

int generateRandom(int min, int max){
    int random = rand() % (max - min + 1) + min;
    return random;
}

int findSum(int &length, int * pArr){
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += pArr[i];
    }
    return sum;
}

void q1c(int &length, int * pArr){
    cout << "Please enter the length of the array: " << endl;
    cin >> length;

    pArr = new int[length];

    for (int i = 0; i < length; i++){
        pArr[i] = generateRandom(1, 50);
    }

    int sum = findSum(length, pArr);
    cout << "The sum is " << sum << endl;
    delete[] pArr;
}

void q1d(int& length1, int& length2, int * pArr1, int * pArr2,int * pArr3){
    cout << "Please enter the length of the first array: " << endl;
    cin >> length1;
    cout << "Please enter the length of the second array: " << endl;
    cin >> length2;

    pArr1 = new int[length1];
    pArr2 = new int[length2];

    for (int i = 0; i < length1; i++){
        cout << "Please enter an element of the first array" << endl;
        cin >> pArr1[i];
    }

    for (int i = 0; i < length2; i++){
        cout << "Please enter an element of the second array" << endl;
        cin >> pArr2[i];
    }

    pArr3 = new int[length1 + length2];
    for (int i = 0; i < length1; i++){
        pArr3[i] = pArr1[i];
    }

    for (int i = 0; i < length2; i++){
        pArr3[i + length1] = pArr2[i];
    }

    for (int i = 0; i < length1 + length2; i++){
        cout << pArr3[i];
    }

}

int main(){
    srand(time(NULL));
    //Q1
    int length;
    int * arrPointer;
    q1a(length, arrPointer);
     
    //Q2
    int length2;
    int * pArr2;
    q1b(length2, pArr2);

    //Q3
    int length3;
    int * pArr3;
    q1c(length3, pArr3);

    //Q4
    int length4, length5;
    int * pArr4, * pArr5, *pArr6;
    q1d(length4, length5, pArr4, pArr5, pArr6);

    return 0;
}