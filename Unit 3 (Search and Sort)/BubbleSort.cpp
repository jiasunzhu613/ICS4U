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

void q1(vector<int> arr, int length)
{
    bool sorted = false;
    for(int i = length-1; i > 0 && !sorted; i--)
    {
        sorted = true;
        for (int j = 0; j < i; j++)
        {
            for (int x = 0; x < length; x++){
                if (x == j)
                    cout << "(" << arr[x] << " ";
                else if (x == j + 1 )
                    cout << arr[x] << ")" << " ";
                else
                    cout << " " << arr[x] << " ";
            }
            cout << endl;
            if (arr[j] > arr[j+1])
            {
                sorted = false;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int x = 0; x < length; x++){
        cout << arr[x] << "  ";
    }
    cout << endl;
}

void q3(vector<int> arr, int length)
{
    int start = 0;
    int end = length - 1;
    long long counter = 0;
    while (counter < 2){
        for (int j = start; j < end; j++)
        {
            for (int x = 0; x < length; x++){
                if (x == j)
                    cout << "(" << arr[x] << " ";
                else if (x == j + 1)
                    cout << arr[x] << ")" << " ";
                else
                    cout << " " << arr[x] << " ";
            }
            cout << endl;
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }

        end--;
        counter++;

        for (int j = end - 1; j >= start ; j--)
        {
            for (int x = 0; x < length; x++){
                if (x == j)
                    cout << "(" << arr[x] << " ";
                else if (x == j + 1 )
                    cout << arr[x] << ")" << " ";
                else
                    cout << " " << arr[x] << " ";
            }
            cout << endl;
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
        start--;
        counter++;
    }
    for (int x = 0; x < length; x++){
        cout << arr[x] << "  ";
    }
    cout << endl;
}

void shakerSort(vector<double> arr, int length)
{
    bool sorted = false;
    int start = 0;
    int end = length - 1;
    int swaps = 0;
    while (!sorted){
        sorted = true;

        for (int j = start; j < end; j++)
        {
            if (arr[j] > arr[j+1])
            {
                sorted = false;
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }

        end--;

        for (int j = end - 1; j >= start ; j--)
        {
            if (arr[j] > arr[j+1])
            {
                sorted = false;
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }

        start++;
    }
    for (int x = 0; x < length; x++){
        cout << arr[x] << " ";
    }
    cout << endl;
    cout << swaps << endl;
}

int main(){
    //Parse Input
    int N;
    cin >> N;
    vector<double> arr = {};
    for (int i = 0; i < N; i++){
        double x;
        cin >> x;
        arr.push_back(x);
    }

    //Q1
    cout << "Q1" << endl;
    vector<int> arr1 = {3 ,8 ,3 ,2 ,7 ,5};
    q1(arr1, 6);

    //Q2
    /*
     * By changing arr[j] > arr[j+1] to arr[j] < arr[j+1], we can sort in reversed order.
     */

    //Q3
    cout << "Q3" << endl;
    vector<int> arr2 = {2, 9 ,4 ,6 ,1 ,7 ,4};
    q3(arr2, 7);

    //Q4
    cout << "Q4" << endl;
    shakerSort(arr, N);

    return 0;
}