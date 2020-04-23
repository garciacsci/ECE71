/* Homework hw33 */

/* 
 * File:    hw33.cpp
 * Author:  Christopher Garcia
 * Purpose: Print the average of the elements stored in a dynamic array created
 *          by an integer entered by the user
 * Date:    April 22, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <iomanip>

using namespace std;

//----------------------------------------------------------------------------//

int main(int argc, char** argv) 
{
    // Declare Variables
    int n;
    double *p, e, sum=0;
    
    // Prompt for and read in size of array
    cout << "Enter size of the dynamic array: ";
    cin >> n;
    cout << endl;
    
    // Create dynamic array
    p= new double[n];
    
    // Enter for loop to prompt user to populate array
    for (int i=0; i<n; i++)
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> e;
        sum+=e;
    }

    // Set output format
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // Print average    
    cout << "\nThe average is " << sum/n;
    
    // Exit Program    
    exit(EXIT_SUCCESS);
}
