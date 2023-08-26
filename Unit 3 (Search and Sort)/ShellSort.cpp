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
 * for many values of K, we K-sort the list, by sorting all of the K elements. to K-Sort the list, we use insertion sort
 *
 */

void kSortSublist(vector<int> arr, int k, int start, int length){
    for (int top = start + k; top < length; top += k)
    {
        int item = arr[top]; //temporary store for current item
        int i = top;
        while (i > start && item < arr[i-k])
        {
// shift larger items to the right by k
            arr[i] = arr[i-k];
// prepare to check the next item, k spaces left
            i = i - k;
        }
        arr[i] = item; // put sorted item in open location
    }
}

void Q1(vector<int> arr, int length){
    int k = 5;
    for (int start = 0; start < length; start++){
        for (int top = start + k; top < length; top += k)
        {
            int item = arr[top]; //temporary store for current item
            int i = top;
            while (i > start && item < arr[i-k])
            {
// shift larger items to the right by k
                arr[i] = arr[i-k];
// prepare to check the next item, k spaces left
                i = i - k;
            }
            arr[i] = item; // put sorted item in open location
        }
    }
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Q2(vector<int> arr, int length){
    int k = 4;
//    cout << k << length << endl;
    for (int start = 0; start < length; start++){
        for (int top = start + k; top < length; top += k)
        {
            int item = arr[top]; //temporary store for current item
            int i = top;
            while (i > start && item < arr[i-k])
            {
// shift larger items to the right by k
                arr[i] = arr[i-k];
// prepare to check the next item, k spaces left
                i = i - k;
            }
            arr[i] = item; // put sorted item in open location
        }
    }
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int generateRandom(int min, int max){
    int random = rand() % (max - min + 1) + min;
    return random;
}

void shellSort(vector<int> arr, int length){
    int k = 1;
    while (k < ceil(length / 3)){
        k *= 3;
        k++;
    }
    k--;
    k /= 3;

    while (k >= 1){
        for (int start = 0; start < length; start++){
            for (int top = start + k; top < length; top += k)
            {
                int item = arr[top]; //temporary store for current item
                int i = top;
                while (i > start && item < arr[i-k])
                {
// shift larger items to the right by k
                    arr[i] = arr[i-k];
// prepare to check the next item, k spaces left
                    i = i - k;
                }
                arr[i] = item; // put sorted item in open location
            }
        }
        cout << k << "k sort list: " << endl;

        for (int i = 0; i < length; i++) {
            cout << arr[i];
            if (i != length - 1) {
                if (i % 10 == 9) cout << endl;
                else cout << " ";
            }
        }
        cout << endl << endl;
        k--;
        k /= 3;
    }
}

void Q6(){
    int length = 10000;
    vector<int> arr = {};
    for (int i = 0; i < length; i++){
        arr.push_back(generateRandom(1, 500));
//        cout << arr[i] << " ";
    }
//    cout << endl;
    cout << time(NULL) << endl;
    int k = 1;
    while (k < ceil(length / 100)){
        k *= 100;
        k++;
    }
    k--;
    k /= 100;

    while (k >= 1){
        for (int start = 0; start < length; start++){
            for (int top = start + k; top < length; top += k)
            {
                int item = arr[top]; //temporary store for current item
                int i = top;
                while (i > start && item < arr[i-k])
                {
// shift larger items to the right by k
                    arr[i] = arr[i-k];
// prepare to check the next item, k spaces left
                    i = i - k;
                }
                arr[i] = item; // put sorted item in open location
            }
        }
        k--;
        k /= 100;
    }
    cout << time(NULL) << endl;
//    for (int i = 0; i < length; i++){
//        cout << arr[i] << " ";
//    }
//    cout << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> li = {};
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        li.push_back(x);
    }

    cout << "Q1" << endl;
    vector<int> arr = {26, 37, 21, 41, 63, 19, 61, 72, 55, 29, 47, 18, 26, 22};
    int length = 14;
    Q1(arr, length);

    cout << "Q2" << endl;
    vector<int> arr2 = {19, 18, 21, 22, 29, 26, 37, 26, 41, 63, 47, 61, 72, 55 };
    int length2 = 14;
    Q2(arr2, length2);

    /*
     * Q3
     * Although shell sort does perform one final pass by 1-sorting (or simply sorting) the array, the array has
     * already been partially sorted due to previous passes of shell sort at higher K values. This makes it so the final
     * pass doesn't have to do as many items swaps as many elements have already been sorted to be in the right position.
     */

    /*
     * Q4
     *
     * a)
     * int k = 1;
        while (k < ceil(length / 3)){
        k *= 3;
        k++;
        }
     *
     * b)
     * k--;
     * k /= 3;
     */

    cout << "Q5" << endl;

    shellSort(li, N);

//    Q6();

    /*
     * Q6:
     *
     * Using (tn-1 * 3) + 1
     * -> about 1 second required to sort 10^4 elements
     *
     * Using (tn-1 * 4) + 1
     * -> less than 1 second required to sort 10^4 elements
     *
     * Using (tn-1 * 10) + 1
     * -> about 1 second required to sort 10^4 elements
     *
     * Using (tn-1 * 100) + 1
     * -> less than 1 second required to sort 10^4 elements
     * -> although this would most likely pose problems for smaller length arrays since many times the first k-sort would
     * be a 1-sort which is an insertion sort.
     *
     * Based on these tests, it does not show the k values refered to in the notes as the most ideal, as (tn-1 * 4) + 1
     * performed better than (tn-1 * 4) + 1. However, I think the k-values for this sort may also vary in performance
     * with array lengths (not sure if this is correct).
     */










    return 0;
}