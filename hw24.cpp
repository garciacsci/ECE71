/* Homework 24*/

/* 
 * File:    hw24.cpp
 * Author:  Christopher Garcia
 * Purpose:  
 * Date:    March 26, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Declare and initialize constants
const int SIZE=100;

// Function Prototypes
void checkFailure(ifstream &fin1, ifstream &fin2);
// Precondition: The files are open
// Checks if any files failed to open

//------------------------------------------------------------------------------

void inputData(ifstream &fin1, ifstream &fin2, double a[], int n);   
// Precondition: An array and size have been made, and the files are open
// Copies the contents of the files into the array

//------------------------------------------------------------------------------

void sortData(double a[], int n);
//Precondition: length <= declared size of the array arr.
//The array elements arr[0] through a[length - 1] have values.
//Postcondition: The values of arr[0] through arr[length - 1] have
//been rearranged so that arr[0] <= a[1] <= ... <= arr[length - 1].

//------------------------------------------------------------------------------

void printResults(const double a[], int n);
// Precondition: The elements of the array are sorted in ascending order
// Prints contents of array in ascending order to screen

int main(int argc, char** argv) 
{
    // Declare Variables
    ifstream fin1, fin2;
    double a[SIZE];
    
    // Open Files
    fin1.open("numbers1.txt");
    fin2.open("numbers2.txt");
    
    // Make sure the input files open successfully
    checkFailure(fin1, fin2);
    
    // Feed the data from the files into an array
    inputData(fin1, fin2, a, SIZE);
    
    // Sort the data in the array
    sortData(a,SIZE);
    
    // Print the sorted data to the screen
    printResults(a, SIZE);
    
    // Close Files
    fin1.close();
    fin2.close();
    
    // Exit Program
    exit(EXIT_SUCCESS);
}

//------------------------------------------------------------------------------

// Define User-Defined Functions
void checkFailure(ifstream &fin1, ifstream &fin2)
{
    // Check to see if any of the files failed to open
    if (fin1.fail())
    {
        cout << "Input file " << "\"" << "Numbers1.txt" << "\"" \
                << "failed to open";
        exit(EXIT_FAILURE);
    }
    else if (fin2.fail())
    {
        cout << "Input file " << "\"" << "Numbers1.txt" << "\"" \
                << "failed to open";
        exit(EXIT_FAILURE);
    }
    else
    {
        // Exit Function
        return;
    }
}

//------------------------------------------------------------------------------

void inputData(ifstream &fin1, ifstream &fin2, double a[], int n)  
{
    // Declare variables
    int i=0;
    
    // Copy contents from input file 1 into array    
        for (i; i<n && !fin1.eof(); i++)
        {
            fin1 >> a[i];
        }
    // Copy contents from input file 2 into array
        for (i--; i<n && !fin2.eof(); i++)
        {
            fin2 >> a[i];
        }
    // Exit function
    return;
}

//------------------------------------------------------------------------------

void sortData(double a[], int n)
{
        // Bubble largest number toward the right
        for (int i = n-1; i > 0; i--)
                for (int j = 0; j < i; j++)
                        if (a[j] > a[j+1])
                        {
                                // Swap the numbers
                                double temp = a[j+1];
                                a[j+1] = a[j];
                                a[j] = temp;
                        }
        // Exit the function
        return;
}

//------------------------------------------------------------------------------

void printResults(const double a[], int n)
{
    // Declare Variables
    int line=1;
    
    // Set formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(8);
    
    // Print Results in two columns
    for (int i=0; i<SIZE; i++)
        cout << setw(3) << line++ << "\t\t" << setw(10) << a[i] << endl;
    
    // Exit function
    return;
}
