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

int power(int base, int expo){
    if (expo == 0){
        return 1;
    }

    return base * power(base, expo - 1);
}

unordered_map<int, int> memo = {};
int fib(int n){
    if (n == 0){
        return 0;
    }
    if (n == 1 or n == 2){
        return 1;
    }
    if (memo.find(n) != memo.end()){
        return memo[n];
    }
    int calc = fib(n - 1) + fib(n - 2);
    memo[n] = calc;
    return calc;
}

void printArr(int * arr, int index, int length){
    if (index == length){
        return;
    }

    cout << arr[index] << " ";
    printArr(arr, index + 1, length);
}

int generateRandom(int min, int max){
    return rand() % (max - min + 1) + min;
}

void init_array(int * arr, int ind, int length){
    if (ind == length)
        return;

    arr[ind] = generateRandom(1, 50);
    init_array(arr, ind + 1, length);
}

void twopower(int start, int end){
    if (start == end)
        return;

    cout << pow(2, start) << " ";
    twopower(start + 1, end);
}

int sum(int * arr, int ind, int length){
    if (ind == length)
        return 0;
    return arr[ind] + sum(arr, ind + 1, length);
}

int largest(int * arr, int ind, int length){
    if (ind == length){
        return -100000000;
    }
    return max(arr[ind], largest(arr, ind + 1, length));
}

double birthdayParadox(int people){
    if (people == 0){
        return 1;
    }
    return ((365-people+1)/365.0) * birthdayParadox(people - 1);
}


int main(){
    srand(time(NULL));
    int base, expo;
    cin >> base;
    cin >> expo;
    cout << power(base, expo) << endl;

//    int n;
//    cin >> n;
//    cout << fib(n) << endl;

//    int length;
//    int * arr;
//    cin >> length;
//    arr = new int[length];
//    for (int i = 0; i < length; i++){
//        cin >> arr[i];
//    }
//    printArr(arr, 0, length);

//    int * arr;
//    arr = new int[10];
//    init_array(arr, 0, 10);
//    for (int i = 0; i < 10; i++){
//        cout << arr[i] << " ";
//    }

//    int end;
//    cin >> end;
//    twopower(0, end);

//    int length;
//    int * arr;
//    cin >> length;
//    arr = new int[length];
//    for (int i = 0; i < length; i++){
//        cin >> arr[i];
//    }
//    cout << sum(arr, 0, length) << endl;

//    int length;
//    int * arr;
//    cin >> length;
//    arr = new int[length];
//    for (int i = 0; i < length; i++){
//        cin >> arr[i];
//    }
//    cout << largest(arr, 0, length) << endl;

//    int people;
//    cin >> people;
//    cout << 1.0 - birthdayParadox(people) << endl;
    return 0;
}