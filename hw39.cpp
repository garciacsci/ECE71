/* Homework hw39*/

/* 
 * File:    hw39.cpp
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

// Function Prototypes
double average(double *p, int n);
// Returns the average of a variable length array
void print(ostream &out, double *p, int n);
// Prints values in the variable length array to the screen or file.

// Define Main Function
int main(int argc, char** argv) 
{
    // Declare Variables
    ofstream fout;
    double *p;
    int n;
    
    // Open output file
    fout.open("values.txt");
    
    // Prompt for size of array
    cout << "Enter number of values: ";
    cin >> n;
    
    // Create variable length array
    p =  new double[n];
    
    // Prompt for and read values into array
    for(int i=0; i<n; i++)
    {
        cout << "Enter a number: ";
        cin >> p[i];
    }

    cout << endl;
    
    //Print to screen
    print(cout, p, n);
    
    //Print to file
    print(fout, p, n);
    
    // Delete array
    delete [] p;
    
    // Set p to null
    p=NULL;
    
    // Close file
    fout.close();
    
    // Exit Program
    exit(EXIT_SUCCESS);
}

// Define User Defined Functions
double average(double *p, int n)
{
    // Declare variables
    double ave=0;
    
    // Get sum of values in array
    for (int i=0; i<n; i++)
    {
        ave+= p[i];
    }

    // Calculate average
    ave = ave/n;
    
    // Return average
    return(ave);
}
void print(ostream &out, double *p, int n)
{
    // Formatting
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);
    
    // Parse array
    // Printing values to screen or file
    out << "Values: ";
    for (int i=0; i<n; i++)
    {       
        // Print values to screen or file
        out << p[i] << ' ';
    }
    // Print average to screen or file    
    out << "\nAve: " << average(p, n);
    
    // Exit function
    return;
}
