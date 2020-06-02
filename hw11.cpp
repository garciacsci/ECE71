/* Homework 11*/

/* 
 * Name:    hw11.cpp
 * Purpose: Return the largest of two or three given values.
 * Author:  Christopher Garcia
 * Date:    24 February 2020
 */

// Preprocessor Directives
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
double max(double x, double y);

// take in two numbers and return the maximum

double max(double x, double y, double z);
// take in three values and return the maximum

// Define Main Function
int main(int argc, char** argv) {
    // Declare Variables
    double x, y, z;
    
    // Prompt for and read in x and y
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    
    // Set precision, show decimal, and set fixed notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // Output maximum of the two values entered
    cout << "\nThe maximum value is: " << max(x, y);
    cout << "\n\n";
            
    // Prompt for and read in x, y, and z
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << "Enter z: ";
    cin >> z;
    
    // Output maximum of the three values entered
    cout << "\nThe maximum value is: " << max(x, y, z);
    
    // Exit program
    return 0;
}

double max(double x, double y)
{
    if (x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

double max(double x, double y, double z)
{
    if (x>y && x>z)
    {
        return x;
    }
    else if (y>x && y>z)
    {
        return y;
    }
    else
    {
        return z;
    }
}
