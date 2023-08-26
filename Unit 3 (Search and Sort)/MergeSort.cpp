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
#include <sys/timeb.h>
#include <cassert>

using namespace std;


/*
 * How does mergesort work:
 *
 * - Starting with unsorted array
 * - we divide the array into 2 sections continuously until we can no longer do so and sort each subsection of the array
 * - we then sort the entire array by merging the sorted subsections
 */

int count2 = 0;

void merge(vector<string> &arr, int N, int start, int mid, int end){
    vector<string> temp (N + 10);
    fill(temp.begin(),temp.end()," ");
    int pos1 = start;
    int pos2 = mid + 1;
    int spot = start;

    while (!(pos1 > mid && pos2 > end)){
        if ((pos1 > mid) || (arr[pos2] < arr[pos1] && pos2 <= end)){
            temp[spot] = arr[pos2];
            pos2++;
        }else{
            temp[spot] = arr[pos1];
            pos1++;
        }
        spot++;
    }

    for (int i = start; i <= end; i++){
        arr[i] = temp[i];
    }
}

void mergesort(vector<string> &arr, int N, int start, int end){
    count2++;
    if (start < end){
        int mid = (start + end) / 2;
        mergesort(arr, N, start, mid);
        mergesort(arr, N, mid + 1, end);
        merge(arr, N, start, mid, end);
    }
}

int main(){
    string n;
    getline(cin, n);
    int N = stoi(n);
    string s;
    getline(cin, s);
    vector<string> arr = {};
    string temp;
    for (char i : s){
        if (i == ' '){
            arr.push_back(temp);
            temp = "";
            continue;
        }
        temp += i;
    }
    arr.push_back(temp);

    mergesort(arr, N, 0, N - 1);

    cout << count2 << endl;
    for (int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}