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

/*
 * A method for constructing a magic square of odd order

Starting from the central column of the first row with the number 1, the fundamental movement for filling the
squares is diagonally up and right, one step at a time. If a filled square is encountered, one moves vertically down one
square instead, then continuing as before. When a move would leave the square, it is wrapped around to the last row or
first column, respectively.

An Algorithm for generating a 5 by 5 magic square:

a) Declare a 5 by 5 array and initialize its values to 0

b) Assign 1 to middle column of the first row

c) for numbers from 2 to 25 repeat following (do all integers 1 to S?)

d) move one row up and one column to the right

e) if your moves takes you of the board at the top, do the same move in the last row

f) if your moves takes you of the board at the right, do the same move in the first column

g) if the position is free (still has a zero in it) assign the number to the position
otherwise, move one row down and assign the number.
 */

bool checkMagicSquare(int**arr, int N, int S){
    //row check
    for (int i = 0; i < N; i++){
        int sum = 0;
        for (int j = 0; j < N; j++){
            sum += arr[i][j];
        }
        if (sum != S){
            return false;
        }
    }

    //col check
    for (int i = 0; i < N; i++){
        int sum = 0;
        for (int j = 0; j < N; j++){
            sum += arr[j][i];
        }
        if (sum != S){
            return false;
        }
    }

    //diag check
    int sum = 0;
    for (int i = 0; i < N; i++){
        sum += arr[i][i];
    }
    if (sum != S){
        return false;
    }

    int sum2 = 0;
    for (int i = N - 1; i > -1; i--){
        sum2 += arr[i][i];
    }
    if (sum2 != S){
        return false;
    }
    return true;

}
int** printMagicSquare(int N, int S){
    int **arr;
    arr = new int*[N];
    for (int i = 0; i < N; i++){
        arr[i] = new int[N];
    }
    int mid = (int) (N / 2);
    int curr_r = 0;
    int curr_c = mid;
    int curr_num = (int)(S/N)-(int)((N*N - 1)/2);
    int iter = 0;
     arr[curr_r][curr_c] = curr_num;
    curr_num++;

    while (iter < (N * N) - 1){
//        cout << "STILL GGOING" << endl;
        int temp_curr_r = curr_r - 1;
        int temp_curr_c = curr_c + 1;
        if (temp_curr_r < 0){
            temp_curr_r = N - 1;
        }
        if (temp_curr_c > N - 1){
            temp_curr_c = 0;
        }

        if (arr[temp_curr_r][temp_curr_c] == 0){
            arr[temp_curr_r][temp_curr_c] = curr_num;
            curr_r = temp_curr_r;
            curr_c = temp_curr_c;
        }else{
            curr_r++;
            arr[curr_r][curr_c] = curr_num;
        }
//        for (int i = 0; i < N; i++){
//            for (int j = 0; j < N; j++){
//                cout << arr[i][j] << " ";
//            }
//            cout << endl;
//        }
        curr_num++;
        iter++;
    }
    return arr;
}

int main(){
    int N, S;
    cin >> N;
    cin >> S;

    int **magicSquare = printMagicSquare(N, S);
//    cout << checkMagicSquare(magicSquare, N, S) << endl;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << magicSquare[i][j];
            if (j != N - 1){
                cout << " ";
            }
        }
        if (i != N - 1){
            cout << endl;
        }
    }
    return 0;
}

