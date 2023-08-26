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

void insertionSort (vector<int> arr, int length){
    for (int x = 0; x < length; x++){
        cout << arr[x] << " ";
    }
    cout << endl;
    int current, temp;
    for (int i = 1; i < length; i++){
        current = i;
        while (current > 0 && arr[current] < arr[current-1]){
            temp = arr[current];
            arr[current] = arr[current-1];
            arr[current-1] = temp;
            current--;
        }
        for (int x = 0; x < length; x++){
            cout << arr[x] << " ";
        }
        cout << endl;
    }
}

void reverseInsertionSort (vector<int> arr, int length){
    int current, temp;
    for (int i = 1; i < length; i++){
        current = i;
        while (current > 0 && arr[current] > arr[current-1]){
            temp = arr[current];
            arr[current] = arr[current-1];
            arr[current-1] = temp;
            current--;
        }
    }
}

void planetInsertionSort (vector<string> arr, int length){
    for (int x = 0; x < length; x++){
        cout << arr[x] << " ";
    }
    cout << endl;
    int current;
    string temp;
    for (int i = 1; i < length; i++){
        current = i;
        while (current > 0 && arr[current] < arr[current-1]){
            temp = arr[current];
            arr[current] = arr[current-1];
            arr[current-1] = temp;
            current--;
        }
        for (int x = 0; x < length; x++){
            cout << arr[x] << " ";
        }
        cout << endl;
    }
}

void findMedian(vector<float> arr, int N){
    if (N % 2 == 0){
        int ind1 = N / 2;
        float val = (arr[ind1] + arr[ind1 - 1]) / 2.0;
        cout << val << endl;
    }else{
        int ind1 = N / 2;
        float val = arr[ind1];
        cout << val << endl;
    }
}

int main(){
    //Parse Input
    int N;
    cin >> N;
    vector<float> arr = {};
    for (int i = 0; i < N; i++){
        float x;
        cin >> x;
        arr.push_back(x);
    }

    //Q1
    cout << "Q1" << endl;
    vector<int> arr2 = {6,2,8,3,1,7,4};
    insertionSort(arr2, 7);

    //Q2
    //ANS: change the while loop to
    //     while (current > 0 && arr[current] > arr[current-1])
    //this will sort the array in reversed order: reverseInsertionSort(arr2, 7);

    //Q3
    cout << "Q3" << endl;
    vector<string> arr3 = {"mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune"};
    planetInsertionSort(arr3, 8);

    //Q4
    cout << "Q4" << endl;
    sort(arr.begin(), arr.end());
    findMedian(arr, N);

    //Q5
    /*
     * Yes, it is a stable sort. This is because Insertion Sort sorts values based on if the previous value is strictly
     * less than the current value. This means that it will never swap values that are of the same numerical value.
     */

    return 0;
}