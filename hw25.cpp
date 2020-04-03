/* Homework 25*/

/* 
 * File:    hw25.cpp
 * Author:  Christopher Garcia
 * Purpose: Create (and store) a 2-D array of 64 random  integers 
 *          (8 rows and 8 columns) between 1 and 100, then print the elements 
 *          of the array, as well as the element location (row and column) 
 *          of the largest value(s) in the array. 
 * Date:    April 2, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Declare and initialize constants
const int ROWS=8;
const int COLS=8;

//------------------------------------------------------------------------------

// Function prototypes
void seedRNG(unsigned int seed); 
// seeds the Random Number Generator with the "seed" value

int randNum(void);
// Returns a random number between 1-100

void populateArray(int a[ROWS][COLS]);
// Populates an array with random values between 1-100

int findMax(int a[ROWS][COLS]);
// Returns the maximum value of the array

void printArray(int a[ROWS][COLS]);
// Prints the 2-D array

void printMax(int a[ROWS][COLS], int max);
// Prints the row, column location(s) of the maximum value(s) 

void rotateArray(int a[ROWS][COLS], int b[ROWS][COLS]); 
// Rotates array a[][] into b[][] 
// ROW positions in a[][] become column positions in b[][] 
// COLUMN positions in a[][] become row positions in b[][]

//------------------------------------------------------------------------------

int main(int argc, char** argv) 
{
    // Declare variables
    int a[ROWS][COLS], b[ROWS][COLS], max;
    unsigned int seed;
    
    // Prompt the user for a seed
    cout << "Enter a random seed: ";
    cin >> seed;
    
    // Use the user seed to call on the seedRNG function and seed the RNG
    seedRNG(seed);
    
    // Populate the array
    populateArray(a);
    
    // Print the array
    cout << endl;
    printArray(a);
    
    // Find the max
    max = findMax(a);
    
    // Print the location of the largest value(s) in the array
    printMax(a, max);
    
    // Rotate array
    rotateArray(a,b);
    
    // Print the rotated array
    cout << endl;
    cout << endl;
    printArray(b);
    
    // Print the location of the largest value(s) in the array
    printMax(b, max);
    // Exit Program
    
    exit(EXIT_SUCCESS);
}

//------------------------------------------------------------------------------

// Define User Defined Functions
void seedRNG(unsigned int seed)
{
    // Seed RNG
    srand(seed);
    
    // Exit Function
    return;
}



int randNum(void)
{
    // Return random number between 1 and 100
    return((rand()%100)+1);
}

void populateArray(int a[ROWS][COLS])
{
    // Declare Variables
    int row, column=0;
    
    // Populate array
    while (column<COLS)
    {
        for (row=0; row<ROWS; row++)
        {
            a[row][column] = randNum();
        }
    column++;
    }
    
    // Exit function
    return;
}

int findMax(int a[ROWS][COLS])
{
    // Declare Variables
    int row, column=0, max=a[row][column];
    
    // Find max
    while (column<COLS)
    {
        for (row; row<ROWS; row++)
        {
            if (a[row][column] > max)
                max = a[row][column];
        }
    column++;
    row=0;
    }
    
    // Exit function
    return(max);
}

void printArray(int a[ROWS][COLS])
{
    // Declare Variables
    int row, column=0;
    
    // Print array
    while (column<COLS)
    {
        for (row=0; row<ROWS; row++)
        {
            cout << setw(3) << a[row][column] << "   ";
        }
    cout << endl;
    column++;
    }    
    
    // Exit function
    return;
}


void printMax(int a[ROWS][COLS], int max)
{
    // Declare Variables
    int row, column=0;    
    
    // Print max
    while (column<COLS)
    {
        for (row=0; row<ROWS; row++)
        {
            if (a[row][column] == max)
            {
                cout << endl;
                cout << "Maximum Value at element: " \
                        << column << "," << row;
            }
        }
    column++;
    }
    
    // Exit function
    return;
}


void rotateArray(int a[ROWS][COLS], int b[ROWS][COLS])
{
    // Declare Variables
    int row, column=0;
    
    // Rotate array
    while (column<COLS)
    {
        for (row=0; row<ROWS; row++)
        {
            b[row][column] = a[column][row];
        }
    column++;
    }
    
    
    // Exit Function
    return;
}
