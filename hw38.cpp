/* Homework hw38*/

/* 
 * File:    hw38.cpp
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
#include <vector>

using namespace std;

// Declare and Initialize Constants
const int N=4;

// Function Prototypes
double average(vector<double> &x);
// Returns the average of the vector x
void print(ostream &out, vector<double> &x);
// Prints values in the string vector x to the screen or to a file.


// Define Main Function
int main(int argc, char** argv) 
{
    // Declare Variables
    ofstream fout;
    vector<double> x;
    double val;
    
    // Open output file
    fout.open("values.txt");
    
    // Prompt for and read into vector
    for(int i=0; i<N; i++)
    {
        cout << "Enter a number: ";
        cin >> val;
        x.push_back(val);
    }

    cout << endl;
    
    //Print to screen
    print(cout, x);
    
    //Print to file
    print(fout, x);
    
    // Close file
    fout.close();
    
    // Exit Program
    exit(EXIT_SUCCESS);
}

// Define User Defined Functions
double average(vector<double> &x)
{
    // Declare variables
    double ave=0;
    
    // Get sum of values
    for (int i=0; i<x.size(); i++)
    {
        ave+= x[i];
    }

    // Calculate average
    ave = ave/x.size();
    
    // Return average
    return(ave);
}
void print(ostream &out, vector<double> &x)
{
    // Formatting
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);
    
    // Parse array
    // Printing values to screen or file
    out << "Values: ";
    for (int i=0; i<x.size(); i++)
    {       
        // Print values to screen or file
        out << x[i] << ' ';
    }
    // Print average to screen or file    
    out << "\nAve: " << average(x);
    
    // Exit function
    return;
}
