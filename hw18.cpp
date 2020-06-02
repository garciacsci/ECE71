/* Homework 18*/

/* 
 * File:    hw18.cpp
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

// Define Main Function
int main(int argc, char** argv) 
{
    // Declare Variables
    double cRadius, eRadius, sRadius, inc, area, volume;
    
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
    area = ((4.0*PI)*(pow(cRadius,2)));
    volume = ((4.0/3.0)*PI*(pow(cRadius,3)));
    
    cout << "\n" << setw(5) << cRadius << "\t" << setw(5) << area << "\t" << setw(5) << volume;
    
    cRadius = (cRadius + inc);
    }
    
    // Exit Program
    exit(EXIT_SUCCESS);
}
