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

using namespace std;

/*
 * How does quick sort work:
 *
 * - starting with unsorted array
 * - we use the most-left element as the element we are trying to put into place, say this is K
 * - 2 markers, left and right, placed at 0 and list length - 1
 * - using the markers, we separate the list into sections -> less than K, is K, and greater than K
 * - we start at one marker, moving our way towards the center of the list
 * - elements found by the left marker should all be less than K, if they are not less than K, we swap it with the value
 * at the right marker
 * - After we swap, we start traversing from the other marker
 * - This is done until we have found the optimal location for K, where we will subdivide the list further and use recursion
 * to do the same thing to the subdivided lists
 */

void QuickSort(vector<int> &arr, int low, int high){
    /*
     * Arr -> unsorted array
     * N -> Length of array
     */
    /*
     * If moving direction is 0, we are moving left
     * else if it is 1, we are moving right
     */
    int const MOVING_LEFT = 0;
    int const MOVING_RIGHT = 1;

    if (low < high){
        int left = low;
        int right = high;
        int current_direction = MOVING_LEFT;
        int K = arr[left];
        cout << K << " [" << left << " " << right << "]" << endl;
        while (left < right){
            if (current_direction == MOVING_LEFT){
                while (arr[right] >= K and left < right)
                    right--;
                arr[left] = arr[right];
                current_direction = MOVING_RIGHT;
            }
            if (current_direction == MOVING_RIGHT){
                while (arr[left] <= K and left < right)
                    left++;
                arr[right] = arr[left];
                current_direction = MOVING_LEFT;
            }
        }
        arr[left] = K;
        QuickSort(arr, low, left - 1);
        QuickSort(arr, right + 1, high);
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> arr = {};
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    QuickSort(arr, 0, N - 1);
    for (int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}