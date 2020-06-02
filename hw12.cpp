/* Homework 12*/

/* 
 * Name:    hw12.cpp
 * Purpose: Round a variable in various ways.
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
int roundToInteger(double x);
double roundToTenths(double x);
double roundToHundredths(double x);
double roundToThousandths(double x);

// Define Main function
int main(int argc, char** argv) {
    // Declare Variables
    double x=0, value;
    int number, count=0;
    
    // Greet and Prompt for numbers
    cout << "Enter Number of Values to be Averaged: ";
    cin >> number;
    cout << "\n";
    count = number;
    
    // For loop
    for (count <=0; count--;)
    {
        cout << "Enter a number: ";
        cin >> value;
        x += value;
    }
    
    x = x/number;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    
    cout << "\nThe raw average is:\t\t" << x;
    cout << "\n...to the nearest integer:\t" << roundToInteger(x);
    cout << "\n...to the tenths place:\t\t" << roundToTenths(x);
    cout << "\n...to the hundredths place:\t" << roundToHundredths(x);
    cout << "\n...to the thousandths place:\t" << roundToThousandths(x);
    
    // Exit Program
    return 0;
}

int roundToInteger(double x)
{
    return floor(x * 10.0 + 0.5)/10.0;
}
double roundToTenths(double x)
{
    return floor(x * 10.0 + 0.5)/10.0;
}
double roundToHundredths(double x)
{
    return floor(x * 100.0 + 0.5)/100.0;
}
double roundToThousandths(double x)
{
    return floor(x * 1000.0 + 0.5)/1000.0;
}
