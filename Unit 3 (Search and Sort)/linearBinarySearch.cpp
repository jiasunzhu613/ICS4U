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

string linearSearch(vector<int> arr, int val, int N){
    cout << "Linear Search" << endl;
    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            cout << arr[j] << " ";
        }
        cout << endl;
        if (arr[i] == val){
           return "found at index " + to_string(i);
        }
    }
    return "not found";
}

string binarySearch(vector<int> arr, int val, int N){
    cout << "Binary Search" << endl;
    int lo = 0;
    int hi = N - 1;
    int mid = round((lo + hi) / 2.0);

    while (lo <= hi){
//        cout << "DIff" << hi - lo << endl;
        for (int i = lo; i <= hi; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        if (arr[mid] == val) {
            if (hi - lo != 0){
                cout << val << endl;
            }
            return "found at index " + to_string(mid);
        } else if (arr[mid] < val) {
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
        mid = round((lo + hi) / 2.0);
    }
    return "not found";
}

int main(){
    int N;
    int val;
    cin >> N >> val;

    vector<int> arr = {};
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    cout << linearSearch(arr, val, N) << endl << endl;
    cout << binarySearch(arr, val, N) << endl;
    return 0;
}