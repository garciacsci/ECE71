/* Homework hw37*/

/* 
 * File:    hw37.cpp
 * Purpose: 
 * Author:  Christopher Garcia
 * Date:    April 28, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Declare and Initialize Constants
const int N=4;

// Function Prototypes
double average(double x[], int n);
// Returns the average of the array x[] of size n
void print(ostream &out, double x[], int n);
// Prints values in x[n] to the screen or to a file

// Define Main Function
int main(int argc, char** argv) 
{
    // Declare Variables
    ofstream fout;
    double x[N];
    
    // Open output file
    fout.open("values.txt");
    
    // Prompt for and read into array
    for(int i=0; i<N; i++)
    {
        cout << "Enter a number: ";
        cin >> x[i];
    }

    cout << endl;
    
    // Print to screen
    print(cout, x, N);
    
    // Print to file
    print(fout, x, N);
    
    // Close file
    fout.close();
            
    // Exit Program
    exit(EXIT_SUCCESS);
}

// Define User Defined Functions
double average(double x[], int n)
{
    // Declare variables
    double ave=0;
    
    // Get sum of values
    for (int i=0; i<N; i++)
    {
        ave+= x[i];
    }

    // Calculate average
    ave = ave/N;
    
    // Return average
    return(ave);
}
void print(ostream &out, double x[], int n)
{
    // Set formatting
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);
    
    // Parse array and
    // Print values to screen or file
    out << "Values: ";
    for (int i=0; i<n; i++)
    {        
        out << x[i] << ' ';
    }
    
    // Print average to screen or file    
    out << "\nAve: " << average(x, n);
    
    // Exit function
    return;
}
