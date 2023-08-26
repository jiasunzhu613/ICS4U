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

int** print_spiral(int start, int end){
    /*
     * greater than perfect square and less than the perfect square + its square root then we col - 2
     */
    int **arr = new int*[10];
    for (int i = 0; i < 10; i++){
        arr[i] = new int[10];
    }
    int size = end - start;
    int mid = ceil(sqrt(end-start+1) / 2);
//    cout << mid << endl;
    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, 1, 0, -1};
    int factor = 1;
    int counter = 0;
    int curr_op = 0;
    int curr_num = start + 1;
    int curr_r = mid - 1;
    int curr_c = mid - 1;
    for (int i = 2; i <= 9; i++){
        if (size >= i*i && size < i*i + i){
            if (i % 2 == 0){
                curr_c = mid - 2;
//                cout << "above perfect and below" << endl;
            }
            break;
        }
    }
    arr[curr_r][curr_c] = start;
//    cout << arr[curr_r][curr_c] << endl;
    while (curr_num <= end){
        if (counter == 2){
            factor += 1;
            counter = 0;
        }
        if (curr_op >= 4) {
            curr_op = 0;
        }
        for (int i = 0; i < factor; i++){
            curr_r += dr[curr_op];
            curr_c += dc[curr_op];
            arr[curr_r][curr_c] = curr_num;
            curr_num += 1;
            if (curr_num > end){
                return arr;
            }
        }
        counter += 1;
        curr_op += 1;
    }
    return arr;
}

int main(){
//    int min, max;
//    cin >> min;
//    cin >> max;
//    if (min == max){
//        if (min <= 9){
//            cout << " " << min << endl;
//        }else{
//            cout << min << endl;
//        }
//    }else{
//        int **spiral = print_spiral(min, max);
//        int *lastNumber;
//        lastNumber = new int[10];
//        for (int i = 0; i < 10; i++){
//            int lastInd = -1;
//            for (int j = 0; j < 10; j++){
//                if (spiral[i][j] > 0){
//                    lastInd = j;
//                }
//            }
//            lastNumber[i] = lastInd;
//        }
//        int lastRowWithNumbers = 0;
//        for (int i = 0; i < 10; i++){
//            if (lastNumber[i] > -1){
//                lastRowWithNumbers = i + 1;
//            }
//        }
//        for (int i = 0; i < lastRowWithNumbers; i++){
//            for (int j = 0; j < 10; j++){
////            if (spiral[i][j] != 0){
////                cout << spiral[i][j] << " ";
////            }
////            cout << spiral[i][j] << " ";
//                if (spiral[i][j] != 0 && spiral[i][j] > 9){
//                    cout << spiral[i][j] << " ";
//                }else if (spiral[i][j] != 0 && spiral[i][j] <= 9){
//                    cout << " " << spiral[i][j] << " ";
//                }else if (j < lastNumber[i]){
//                    cout << "   ";
//                }
//            }
//            cout << endl;
//        }
//    }
    int T;
    cin >> T;
//    srand(time(NULL));
    for (int trial = 0; trial < T; trial++){
       /* int min = rand() % (99 - 1 + 1) + 1;
        int max = rand() % (99 - min + 1) + min;
        cout << min << " and " << max << endl;*/
        int min, max;
        cin >> min;
        cin >> max;
        if (min == max){
            if (min <= 9){
                cout << " " << min << endl;
            }else{
                cout << min << endl;
            }
        }else{
            int **spiral = print_spiral(min, max);
            int *lastNumber;
            int highest = 0;
            lastNumber = new int[10];
            for (int i = 0; i < 10; i++){
                int lastInd = -1;
                for (int j = 0; j < 10; j++){
                    if (spiral[i][j] > 0){
                        lastInd = j;
                    }
                }
                if (lastInd > highest){
                    highest = lastInd;
                }
                lastNumber[i] = lastInd;
            }
            int lastRowWithNumbers = 0;
            for (int i = 0; i < 10; i++){
    //                cout << lastNumber[i] << endl;
                if (lastNumber[i] > -1){
                    lastRowWithNumbers = i + 1;
                }
            }
    //        cout << highest << endl;
            for (int i = 0; i < lastRowWithNumbers; i++){
                for (int j = 0; j < 10; j++){
                    if (spiral[i][j] != 0 && spiral[i][j] > 9){
                        cout << spiral[i][j];
                    }else if (spiral[i][j] != 0 && spiral[i][j] <= 9){
                        cout << " " << spiral[i][j];
                    }else if (j <= highest){
                        cout << "  ";
                    }
                    if (j < highest){
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
    }

}