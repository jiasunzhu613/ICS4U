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

double average(int arr[], int ind){
     if (ind == 0)
         return arr[0];
     return average(arr, ind - 1) + (1.0/ind)*(arr[ind - 1] - average(arr, ind - 1));
}

int main(){
    int length;
    int * arr;
    cin >> length;
    arr = new int[length];
    for (int i = 0; i < length; i++){
        cin >> arr[i];
    }
    printf("%.1f", average(arr, length));
    return 0;
}