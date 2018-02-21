/* 
 * File:   main.cpp
 * Author: Rosangelica Santacruz
 * Created on February 21, 2018, 12:46 AM
 * Purpose:  Develop a 2D Array structure
 *     with potential future for different #cols per row
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Struct2D.h"

// Function Prototypes
Array2D *filStrc(int, int);
void prtStrc(Array2D *);
void destroy(Array2D *);
void mrkSort(Array2D *, int);

int main(int argc, char** argv) {
    // Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    // Declare and initialize the 2D Structure
    Array2D* myArray;
    myArray = filStrc(10, 15);
    
    // Display the contents of the 2D Structure
    prtStrc(myArray);
    
    // Sort a column of the array
    mrkSort(myArray, 5);
    
    // Display the contents
    prtStrc(myArray);
    
    // Destroy allocated memory
    destroy(myArray);

    return 0;
}

void destroy(Array2D *myArray) {
    for (int i = 0; i < myArray->rows; i++) {
        delete []myArray->data[i];
    }
    
    delete []myArray->data;
    delete myArray;
}

void mrkSort(Array2D *a, int col) {
    for (int i = 0; i < a->rows - 1; i++) {
        for(int j = i + 1; j < a->rows; j++) {
            if (a->data[i][col] > a->data[j][col]) {
                for (int k = 0; k < a->cols; k++) {
                    int temp = a->data[i][k];
                    a->data[i][k] = a->data[j][k];
                    a->data[j][k] = temp;
                }
            }
        }
    }
}

Array2D* filStrc(int rows, int cols) {
    Array2D *temp = new Array2D;
    
    // Fill the 2D array Structure
    temp->rows = rows;
    temp->cols = cols;
    
    temp->data = new int*[temp->rows];
    for (int i = 0; i < temp->rows; i++) {
        temp->data[i] = new int[cols];
    }
    
    // Fill array with random values
    for (int i = 0; i < temp->rows; i++) {
        for (int j = 0; j < temp->cols; j++) {
            temp->data[i][j] = rand() % 90 + 10;
        }
    }
    
    return temp;
}

void prtStrc(Array2D *myArray) {
    cout << "Structure data array size => rows = " << myArray->rows << " cols = " << myArray->cols << endl << endl;
    
    for (int i = 0; i < myArray->rows; i++) {
        for (int j = 0; j < myArray->cols; j++) {
            cout << myArray->data[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl << endl;
}
