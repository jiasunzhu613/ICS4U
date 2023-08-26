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

void q1a()
{
    int row, column;
    int **matrix; // two * are needed because it is a pointer to a pointer
    cout << "please enter the dimesion of the matrix" << endl;
    cin >> row;
    cin >> column;
    matrix = new int *[row]; // creates a new array of pointers to int objects for rows
    for (int i = 0; i < row; ++i)
        matrix[i] = new int[column]; // creates new 'column' number of locations
    cout << "enter the elements of the array " << endl;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            cin >> matrix[i][j];
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < column; c++)
            cout << matrix[r][c] << " ";
        cout << endl;
    }
    for (int r = 0; r < row; r++)
    {
        delete[] matrix[r]; // deallocate each pointer within the pointer array
    }
    delete[] matrix; // deallocate the pointer
}

int generateRandom(int min, int max)
{
    int random = rand() % (max - min + 1) + min;
    return random;
}

double findAvg(int **matrix, int row, int col)
{
    double avg = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            avg += matrix[i][j];
        }
    }
    int numElements = row * col;
    avg /= numElements;
    return avg;
}

void q1b()
{
    // Row and col input
    int row, col;
    int **matrix;
    cout << "Please enter the dimensions of the matrix (starting with the # of rows)" << endl;
    cin >> row;
    cin >> col;

    matrix = new int *[row]; // Initialize new array of pointers for rows
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col]; // initialize new arrays for each column
    }

    // 2D array creation
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = generateRandom(1, 1000);
        }
    }

    // Find average
    double avg = findAvg(matrix, row, col);
    cout << "The average of your values is: " << avg << endl;

    // Deallocate memory
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void printSpaces(int times)
{
    for (int i = 0; i < times; i++)
    {
        cout << "  ";
    }
}
void q1c()
{
    int n;
    int **matrix;
    cout << "Please enter the side length of your square" << endl;
    cin >> n;

    matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }

    cout << "Please enter the elements of your square" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // print out diagonal
    for (int i = 0; i < n; i++)
    {
        printSpaces(i);
        cout << matrix[i][i] << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void q2()
{
    int row, col, row2, col2;
    int **matrix1, **matrix2, **matrix3;
    cout << "Please enter dimensions for first 2D array" << endl;
    cin >> row;
    cin >> col;
    cout << row << col << endl;

    cout << "Please enter dimensions for second 2D array" << endl;
    cin >> row2;
    cin >> col2;
    cout << row2 << col2 << endl;

    // Array set up
    matrix1 = new int *[row];
    for (int i = 0; i < row; i++)
    {
        matrix1[i] = new int[col];
    }

    matrix2 = new int *[row2];
    for (int i = 0; i < row2; i++)
    {
        matrix2[i] = new int[col2];
    }

    cout << "Please enter the elements for the first 2D array" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "Please enter the elements for the second 2D array" << endl;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cin >> matrix2[i][j];
        }
    }

    if (row >= row2)
    {
        matrix3 = new int *[row];
        for (int i = 0; i < row; i++)
        {
            matrix3[i] = new int[col + col2];
        }
        // put matrix 1 in
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix3[i][j] = matrix1[i][j];
            }
        }
        // append matrix 2
        for (int i = 0; i < row2; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                matrix3[i][col + j] = matrix2[i][j];
            }
        }

        // print
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col + col2; j++)
            {
                cout << matrix3[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < row; i++)
        {
            delete[] matrix1[i];
            delete[] matrix3[i];
        }

        delete[] matrix1;
        delete[] matrix3;

        for (int i = 0; i < row2; i++)
        {
            delete[] matrix2[i];
        }

        delete[] matrix2;
    }
    else
    {
        matrix3 = new int *[row2];
        for (int i = 0; i < row2; i++)
        {
            matrix3[i] = new int[col + col2];
        }
        // put matrix 1 in
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix3[i][j] = matrix1[i][j];
            }
        }
        // append matrix 2
        for (int i = 0; i < row2; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                matrix3[i][col + j] = matrix2[i][j];
            }
        }

        // print
        for (int i = 0; i < row2; i++)
        {
            for (int j = 0; j < col + col2; j++)
            {
                cout << matrix3[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < row2; i++)
        {
            delete[] matrix2[i];
            delete[] matrix3[i];
        }

        delete[] matrix2;
        delete[] matrix3;

        for (int i = 0; i < row; i++)
        {
            delete[] matrix1[i];
        }

        delete[] matrix1;
    }
}

void modifyArray(int b[], int arr_size){
    for (int i = 0; i < arr_size; i++){
        b[i] *= 2;
    }
}

void modifyElement(int a)
{
    a *= 2;
}

void q3()
{
    int * element;
    element = new int[5];
    for (int index = 0; index <= 4; index++)
        element[index] = index;
    cout << "Effects of passing entire array call by reference\n\n";
    cout << "Value of the original array is \n";
    for (int x = 0; x <= 4; x++)
        cout << element[x] << " ";
    cout << endl;
    modifyArray(element, 5);
    cout << endl << endl;
    cout << "Effects of passing array element call-by-value\n\n";
    cout << "The value of element[3] is " << element[3] << endl;
    modifyElement(element[3]);
    cout << "The value of element[3] is " << element[3] << endl;
}

int main()
{
    srand(time(NULL));

     // Q1
     q1a();

     // Q2
     q1b();

     // Q3
     q1c();

     // Q4
     q2();

     // Q5
     q3();
    return 0;
}