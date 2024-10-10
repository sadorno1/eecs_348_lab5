/*
# Name: Samantha Adorno
# KUID: 3147214
# LAB Assignment: 05
# Description: Complete operations with matrices
# Note: I didn't know who the TA for this lab was, because it switched a couple times but I wasn't able to go because I had a conference.
I have a university excuse absence, and I wanted to know who to send it to to not lose attendance points, and in case I don't follow
something they said to do in the lab, because I wasn't there. Thank you!
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// function declarations
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);

int main() {
    //defines two matrices
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    
    int result[SIZE][SIZE];  //stores the result of operations

    //add
    printf("Matrix Addition:\n");
    addMatrices(m1, m2, result);
    printMatrix(result);

    // multiplying
    printf("\nMatrix Multiplication:\n");
    multiplyMatrices(m1, m2, result);
    printMatrix(result);

    //transposing
    printf("\nTranspose of Matrix m1:\n");
    transposeMatrix(m1, result);
    printMatrix(result);

    return 0;
}

//function to add two matrices
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

//function to multiply two matrices
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;  //initializes result matrix element to 0
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

//function to transpose a matrix
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];  
        }
    }
}

//function to print a matrix 
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}
