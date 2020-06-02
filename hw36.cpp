/* Homework hw36*/

/* 
 * File:    hw36.cpp
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

// Define Main Function
int main(int argc, char** argv) 
{
    // Declare Variables
    ofstream fout;
    double x, sum=0, ave=0;
    
    // Open output file
    fout.open("values.txt");
    
    // Print values description to file
    fout << "\nValues: ";
    
    // Prompt for and store integers to file
    for (int i=0; i<N; i++)
    {
        cout << "Enter a number: ";
        cin >> x;
        // Write to file
        fout << x << ' ';     
        // Track sum
        sum += x;
    }

    // Calculate and Output average
    fout.setf(ios::fixed);
    fout.setf(ios::showpoint);
    fout.precision(2);
    ave = sum/N;
    fout << "\nAve: " << ave;
    
    // Close output file
    fout.close();

    // Exit Program
    exit(EXIT_SUCCESS);
}
