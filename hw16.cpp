/* Homework 16*/

/* 
 * File:    hw16.cpp
 * Purpose: Compute the
 * Author:  Christopher Garcia
 * Date:    March 3, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>

using namespace std;

// Declare and Initialize Constants
const double PI=3.14159;

// Define Main Function
int main(int argc, char** argv) 
{
    // Declare Variables
    double radius, area, volume;
    
    cout << "Enter Radius: ";
    cin >> radius;
    
    area = ((4.0*PI)*(pow(radius,2)));
    volume = ((4.0/3.0)*PI*(pow(radius,3)));
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "\n" << "Circular Area: " << area;
    cout << "\n" << "Spherical Volume: " << volume;

    // Exit Program
    exit(EXIT_SUCCESS);
}
