/* Homework 17*/

/* 
 * File:    hw17.cpp
 * Purpose: 
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
    char choice;
    double radius, area, volume;
    
    cout << "Calculate Area/Volume of Circle/Sphere (C/S): ";
    cin >> choice;
    cout << "Enter Radius: ";
    cin >> radius;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    if (choice == 'c' || choice == 'C')
    {
    area = ((4.0*PI)*(pow(radius,2)));
    cout << "\n" << "Circular Area: " << area;
    }
    else if (choice == 's' || choice == 'S')
    {
    volume = ((4.0/3.0)*PI*(pow(radius,3)));
    cout << "\n" << "Spherical Volume: " << volume;
    }
    
    // Exit Program
    exit(EXIT_SUCCESS);
}
