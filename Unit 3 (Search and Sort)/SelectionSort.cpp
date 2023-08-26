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

void selectSort(vector<int> arr, int n) {
//pos_max will store the index of the largest element found in the unsortedportion
    int pos_max,temp;
    for (int i=n-1; i > 0; i--) { //i is the index of end of unsorted portion
        for (int x = 0; x < n; x++){
            cout << arr[x] << " ";
        }
        cout << endl;
        pos_max = 0; //assume first element is largest
        for (int j=1; j <= i; j++) {
            if (arr[j] > arr[pos_max])
                pos_max=j; //if larger found, set new largest
        }

//swap element at i with largest element found in unsorted portion
        temp = arr[i];
        arr[i] = arr[pos_max];
        arr[pos_max] = temp;
    }
}

void selectSort(vector<int> arr, int n, int k) {
//pos_max will store the index of the largest element found in the unsortedportion
    int pos_max,temp;
    for (int i=n-1; i > (n - k) - 1; i--) { //i is the index of end of unsorted portion
        pos_max = 0; //assume first element is largest
        for (int j=1; j <= i; j++) {
            if (arr[j] > arr[pos_max])
                pos_max=j; //if larger found, set new largest
        }

//swap element at i with largest element found in unsorted portion
        temp = arr[i];
        arr[i] = arr[pos_max];
        arr[pos_max] = temp;
        if (i == n - k){
            for (int x = 0; x < n; x++){
                cout << arr[x] << " ";
            }
            cout << endl;
        }
    }
}

void wordSelectSort(vector<string> arr, int n) {
    //pos_max will store the index of the largest element found in the unsortedportion
    int pos_max;
    string temp;
    for (int i=n-1; i > 0; i--) { //i is the index of end of unsorted portion
        for (int x = 0; x < n; x++){
            cout << arr[x] << " ";
        }
        cout << endl;
        pos_max = 0; //assume first element is largest
        for (int j=1; j <= i; j++) {
            if (arr[j] > arr[pos_max])
                pos_max=j; //if larger found, set new largest
        }

        //swap element at i with largest element found in unsorted portion
        temp = arr[i];
        arr[i] = arr[pos_max];
        arr[pos_max] = temp;
    }
    for (int x = 0; x < n; x++){
        cout << arr[x] << " ";
    }
    cout << endl;
}

void selectSortFromSmallest(vector<int> arr, int n) {
    int pos_min,temp;
    for (int i=0; i < n; i++) {
        for (int x = 0; x < n; x++){
            cout << arr[x] << " ";
        }
        cout << endl;
        pos_min = n-1;
        for (int j=n-2; j >= i; j--) {
            if (arr[j] < arr[pos_min])
                pos_min=j;
        }

        temp = arr[i];
        arr[i] = arr[pos_min];
        arr[pos_min] = temp;
    }
}

int main(){
    //Parse Input
    int N, K;
    cin >> N >> K;
    vector<int> arr3 = {};
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        arr3.push_back(x);
    }

    //Q1
    cout << "Q1" << endl;
    vector<string> arr1 = {"Robert", "Brian", "Victor" ,"David" ,"Scott"};
    wordSelectSort(arr1, 5);

    //Q2
    /*
     * if arr[j] > arr[pos_max] was changed for arr[j] < arr[pos_max], the array would be sorted in reversed order.
     */

    //Q3
    /*
     * a) To prevent unnecessary swaps, you can check for index equality at the end of each
     * iteration of the for loop (on the outside).
     *
     * b) It may contribute towards the unnecessary running of code.
     */

    //Q4
    cout << "Q4" << endl;
    vector<int> arr2 = {8 ,9, 6, 1, 2, 4};
    selectSortFromSmallest(arr2, 6);

    //Q5
    cout << "Q5" << endl;
    selectSort(arr3, N, K);












    return 0;
}