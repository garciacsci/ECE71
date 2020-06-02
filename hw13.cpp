/* Homework 13*/

/* 
 * File:    hw13.cpp
 * Purpose: Converts from 24-hour time to 12-hour time
 * Author:  Christopher Garcia
 * Date:    March 3, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
void getInput(int &hrs, int &min);
// Reads in and stores the 24 hr time from the user given that they enter it
// as hrs:min
void convertTime(int &hrs, string &ampm);
// converts the hours from the user into 12hr format and sets appropriate
// am/pm tag
void displayOutput(int hrs, int min, string ampm);
// displays the time in 12hr format with appropriate am/pm

// Define Main Function
int main(int argc, char** argv) 
{
    // Declare Variables
    int hrs, min;
    string ampm;
    
    // Prompt for 24hr Time
    cout << "Enter a time in 24 hour format: ";
    
    getInput(hrs, min);
    
    // Convert input
    convertTime(hrs, ampm);
    
    // Output 12hr time
    displayOutput(hrs, min, ampm);

    // Exit Program
    exit(EXIT_SUCCESS);
}

// Define User Defined Functions
void getInput(int &hrs, int &min)
{
    // Declare Variables
    char g;
    
    // Read in hours and minutes
    cin >> hrs >> g >> min;
}

void convertTime(int &hrs, string &ampm)
{
    // Convert 24hr hours to 12hr hours with AM or PM
    if (hrs == 0 || hrs == 24)
    {
        ampm = "AM";
        hrs = 12;
    }
    else if (hrs < 12 && hrs >0)
    {
        ampm = "AM";
    }
    else if (hrs == 12)
    {
        ampm = "PM";
    }
    else if (hrs > 12 && hrs < 24)
    {
        ampm = "PM";
        hrs = hrs-12;
    }
}

void displayOutput(int hrs, int min, string ampm)
{
    // Print 12hr time
    cout << "Time: " << hrs << ":" << setfill('0') << setw(2)
         << min << " " << ampm;
}
