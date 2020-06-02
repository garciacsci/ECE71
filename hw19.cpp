/* Homework 19*/

/* 
 * File:    hw19.cpp
 * Purpose: 
 * Author:  Christopher Garcia
 * Date:    March 3, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <iomanip>

using namespace std;

// Declare and Initialize Constants
const double PI=3.14159;

// Function Prototypes
double circleArea(double radius);
double sphereVolume(double radius);

// Define Main Function
int main(int argc, char** argv) 
{
    // Declare Variables
    double eRadius, inc, area, volume, cRadius, sRadius;
    
    cout << "Enter starting radius: ";
    cin >> sRadius;
    cRadius = sRadius;
    cout << "Enter ending radius: ";
    cin >> eRadius;
    cout << "Enter increment: ";
    cin >> inc;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "\nRadius" << "\t  " << "Ac" << "\t  " << "Vs";
    
    while (cRadius <= eRadius)
    {
    
    cout << "\n" << setw(5) << cRadius << "\t" << setw(5) << circleArea(cRadius) << "\t" << setw(5) << sphereVolume(cRadius);
    
    cRadius = (cRadius + inc);
    }
    
    // Exit Program
    exit(EXIT_SUCCESS);
}

// Define User Defined Functions
double circleArea(double radius)
{
    // Exit Function
    return((4.0*PI)*(pow(radius,2)));
}

double sphereVolume(double radius)
{
    //Exit Function
    return((4.0/3.0)*PI*(pow(radius,3)));
    
}
