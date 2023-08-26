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
void printArr(vector<int> arr, int N){
    for (int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
 * Insertion sort algorithm:
 * - choose an element
 * - continuously compare it to elements before it, if it is smaller swap the two elements if it isnt, stop comparing
 */
void insertionSort(vector<int> arr, int N){
    for (int i = 1; i < N; i++){
        int counter = i;
        while (counter > 0 &&  arr[counter] < arr[counter - 1]){
            int temp = arr[counter];
            arr[counter] = arr[counter - 1];
            arr[counter - 1] = temp;
            counter--;
        }
        printArr(arr, N);
    }
}

void reversedInsertionSort(vector<int> arr, int N){
    for (int i = N - 2; i >= 0; i--){
        int counter = i;
        while (counter < N - 1 && arr[counter] > arr[counter + 1]){
            int temp = arr[counter];
            arr[counter] = arr[counter + 1];
            arr[counter + 1] = temp;
            counter++;
        }
        printArr(arr, N);
    }
}

/*
 * selection sort:
 * - choose an index
 * - find an element that is most suitable for that position
 * - this is done by comparing all unsorted elements in the array
 * eg. if we start at index 0, we try to find the smallest element and put it at that index
 */
void selectionSortFromSmallest(vector<int> arr, int N){
    //loop through the array, i is the indice we are trying to find a suitable value for
    for (int i = 0; i < N; i++){
        //we start at the last position because it is the furthest away
        int pos_min = N - 1;
        //look from second last value to unsorted portion of array to find suitable value
        for (int j = N - 2; j >= i; j--){
            if (arr[j] < arr[pos_min]){
                pos_min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[pos_min];
        arr[pos_min] = temp;
        printArr(arr, N);
    }
    printArr(arr, N);
}

void selectionSortFromLargest(vector<int> arr, int N){
    //loop through the array, i being the index we are trying to find a suitable value for
    for (int i = N - 1; i > 0; i--){
        //assume max to be last position to be sorted
        int pos_max = 0;
        //start at second last position to be sorted
        for (int j = 1; j <= i; j++){
            if (arr[j] > arr[pos_max]){
                pos_max = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[pos_max];
        arr[pos_max] = temp;
        printArr(arr, N);
    }
    printArr(arr, N);
}

/*
 * bubble sort:
 * - start at an index
 * - compare the element to the right of it
 * - swap the two elements if the element to the right is smaller than the element to the left, otherwise move on
 *
 * notes:
 * - use first for loop as a guide for the maximum or minimum index to travel to
 * (this is much easier than doing math to find the index)
 * - have a sorted variable that checks when the array is sorted. The array is sorted whenever bubble sort no
 * longer has to perform swaps
 *
 */
void bubbleSort(vector<int> arr, int N){
    bool sorted = false;
    for (int i = N - 1; i > 0 && !sorted; i--){
        sorted = true;
        for (int j = 0; j < i; j++){
            if (arr[j + 1] < arr[j]){
                sorted = false;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printArr(arr, N);
    }
}

void reversedBubbleSort(vector<int> arr, int N){
    bool sorted = false;
    for (int i = 0; i < N && !sorted; i++){
        sorted = true;
        for (int j = N - 1; j > i; j--){
            if (arr[j - 1] > arr[j]){
                sorted = false;
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
        printArr(arr, N);
    }
}

/*
 * Special variation of bubble sort, where on even and odd intervals the bubble sort is going in different directions
 *
 */
void cocktailSort(vector<int> arr, int N){
    //remember to have swapped variable to be able to end looping if the array has been sorted
    bool swapped = true;
    int start = 0;
    int end = N - 1;
    while (swapped){
        swapped = false;
        //forwards interval
        for (int i = start; i < end; i++){
            if (arr[i + 1] < arr[i]){
                swapped = true;
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        end--;
        printArr(arr, N);

        if (!swapped){
            break;
        }

        swapped = false;
        //backwards interval
        for (int i = end; i >= start; i--){
            if (arr[i - 1] > arr[i]){
                swapped = true;
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
        start++;
        printArr(arr, N);
    }
}

void shellSort(vector<int> arr, int N){
    //find starting k value
    int K = 1;
    while (K < N){
        K *= 3;
        K++;
    }
    K /= 3;

    //main loop for K sorting values
    while (K >= 1){
        //secondary loop for operating k-sorts
        //this for loop is used to k-sort every k-th element starting at the starting point
        for (int start = 0; start < K; start++){
            //preform an insertion sort for each k-th element (aka k-sort)
            /*
             * this insertion is modified to accomodate increments by k
             * since the first iteration of insertion sort is redundant, we start at the value "start + K", just like
             * how insertion sort starts at 1. We also have to change out while loop to fit the interval so we compare
             * the k-th below element from the element we are currently at, while making sure that the while loop does not
             * reach past the start point of "start" in each iteration
             */
            for (int i = start + K; i < N; i += K){
                int counter = i;
                while (counter > start && arr[i] < arr[i - K]){
                    int temp = arr[i];
                    arr[i] = arr[i - K];
                    arr[i - K] = temp;
                    counter -= K;
                }
            }
        }
        printArr(arr, N);
        K /= 3;
    }
}

void quickSort(vector<int> &arr, int lo, int hi){
    // array traveling ->
    int TRAVELING_LEFT = 1;
    // array traveling <-
    int TRAVELING_RIGHT = 0;
    //remember this if statement, as it acts as the base case for the recursion
    if (lo < hi){
        int left = lo;
        int right = hi;
        int pivot = arr[lo];
        int TRAVELING_DIRECTION = TRAVELING_LEFT;
        while (left < right){
            if (TRAVELING_DIRECTION == TRAVELING_LEFT){
                while (arr[right] >= pivot && left < right)
                    right--;
                arr[left] = arr[right];
                TRAVELING_DIRECTION = TRAVELING_RIGHT;
            }
            if (TRAVELING_DIRECTION == TRAVELING_RIGHT){
                while(arr[left] <= pivot && left < right)
                    left++;
                arr[right] = arr[left];
                TRAVELING_DIRECTION = TRAVELING_LEFT;
            }
            printArr(arr, arr.size());
        }
        arr[left] = pivot;
        quickSort(arr, lo, left);
        quickSort(arr, left + 1, hi);
    }
}


/*
 * mergesort:
 * - split the array up into halves until it can no longer be
 */
void merge(vector<int> &arr, int N, int lo, int mid, int hi){
    vector<int> temp(N);
    int pos1 = lo;
    int pos2 = mid + 1;
    int spot = lo;
    if (lo < hi){
        while (!(pos1 > mid && pos2 > hi)){
            //add from higher half
            if ((pos1 > mid) || (arr[pos2] < arr[pos1] && pos2 <= hi)){
                temp[spot] = arr[pos2];
                pos2++;
                spot++;
            }else{//add from lower half
                temp[spot] = arr[pos1];
                pos1++;
                spot++;
            }
        }
    }

    for (int i = lo; i <= hi; i++){
        arr[i] = temp[i];
    }
}


void mergeSort(vector<int> &arr, int N, int lo, int hi){
    if (lo < hi){
        int mid = (lo + hi) / 2;
        mergeSort(arr, N, lo, mid);
        mergeSort(arr, N, mid + 1, hi);
        merge(arr, N, lo, mid, hi);
    }
    printArr(arr, N);
}

//void merge(vector<int> &arr, int N, int lo, int mid, int hi){
//    vector<int> temp(N);
//    int pos1 = lo;
//    int pos2 = mid + 1;
//    int spot = lo;
//    while (!(pos1 > mid && pos2 > hi)){
//        //add from higher than mid
//        /*
//         * in order for the value from position 2 to be added instead of the value from position one
//         * it must either:
//         * - pos1 is off limits -> its already gone too far right
//         * - pos2 value is smaller and pos2 is not off limits meaning that it has not yet gone past the end point
//         *
//         * - every other time, we will add from pos1
//         *
//         * this will help us to eventually completely merge into a sorted array
//         */
//        if ((pos1 > mid) || (arr[pos1] > arr[pos2] && pos2 <= hi)){
//            temp[spot] = arr[pos2];
//            pos2++;
//            spot++;
//        }else{        //add from lower than mid
//            temp[spot] = arr[pos1];
//            pos1++;
//            spot++;
//        }
//    }
//    for (int i = lo; i <= hi; i++){
//        arr[i] = temp[i];
//    }
//}
//
//void mergeSort(vector<int> &arr, int N, int lo, int hi){
//    if (lo < hi){
//        int mid = (lo + hi) / 2;
//        mergeSort(arr, N, lo, mid);
//        printArr(arr, N);
//        mergeSort(arr, N, mid + 1, hi);
//        printArr(arr, N);
//        merge(arr, N, lo, mid, hi);
//    }
//    printArr(arr, N);
//}

int main(){
    vector<int> arr = {6,2,8,3,1,7,4};
    cout << "NORMAL INSERTION SORT" << endl;
    insertionSort(arr, arr.size());
    cout << endl;
    cout << "REVERSED INSERTION SORT" << endl;
    reversedInsertionSort(arr, arr.size());
    cout << endl;
    cout << "SELECTION SORT FROM SMALLEST" << endl;
    selectionSortFromSmallest(arr, arr.size());
    cout << endl;
    cout << "SELECTION SORT FROM LARGEST" << endl;
    selectionSortFromLargest(arr, arr.size());
    cout << endl;
    cout << "BUBBLE SORT" << endl;
    bubbleSort(arr, arr.size());
    cout << endl;
    cout << "REVERSED BUBBLE SORT" << endl;
    reversedBubbleSort(arr, arr.size());
    cout << endl;
    cout << "COCKTAIL SORT" << endl;
    cocktailSort(arr, arr.size());
    cout << endl;
    cout << "SHELL SORT" << endl;
    shellSort(arr, arr.size());
    cout << endl;
    cout << "QUICK SORT" << endl;
    quickSort(arr, 0, arr.size() - 1);
    vector<int> arr2 = {6,2,8,3,1,7,4};
    cout << endl;
    cout << "MERGE SORT" << endl;
    mergeSort(arr2, arr.size(), 0, arr.size() - 1);
    return 0;
}