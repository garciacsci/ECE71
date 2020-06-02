/* Homework 9*/

/* 
 * Name:    hw09.cpp
 * Purpose: Calculates the fuel efficiency of a user's car given
 *          by the number of miles per gallon driven 
 * Author:  Christopher Garcia
 * Date:    21 February 2020
 */

// Preprocessor Directives
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ostream>

using namespace std;

// Function Prototypes
double fuelEfficiency(double liters, double miles);
// Receives liters and miles from main function then computes and returns
// fuel efficiency tot the main program

//Declare and initialize constant
const double GPL = .264179;

//Define Main Function
int main(int argc, char** argv)
{
    //Declare Variables
    double liters, miles, efficiency;
    
    // Prompt for and read in liters and miles on car
    cout << "Enter the liters of gas consumed by the car: ";
    cin >> liters;
    cout << "Enter the miles driven by the car: ";
    cin >> miles;
    cout << "\n";
    
    // Calculate Fuel Efficiency
    efficiency = fuelEfficiency(liters, miles);
    
    // Set notation, precision, and decimal then print fuel efficiency
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << "The fuel efficiency is " << efficiency << " mpg.";
    
    //Exit Program
    exit (EXIT_SUCCESS);
}

double fuelEfficiency(double liters, double miles)
{
    // Declare Variables
    double gallon;
    
    // Calculate gallons
    gallon = liters*GPL;
    
    // Return miles per gallon
    return (miles/gallon);
}
