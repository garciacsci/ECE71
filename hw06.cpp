/* Homework 6*/

/* 
 * Name:    hw06.cpp
 * Purpose: Convert a numerical grade into a letter grade and GPA.
 * Author:  Christopher Garcia
 * Date:    12 February 2020
 */

// Preprocessor Directives
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

// Define Main Function
int main(int argc, char** argv)
{
    
    // Define Variables
    int convertedScore;
    double numericalScore;
    
    //Welcome and prompt user for numerical grade
    cout << "Welcome to the Grade Calculation Program" << "\n" << "\n";
    cout << "Enter Numerical Grade: ";
    
    //Read in Numerical score and convert to tens place integer
    cin >> numericalScore;
    convertedScore = numericalScore/10;
            
    // Check if numerical score is valid
    if (numericalScore>=0 && numericalScore<=100)
    {
        // Output appropriate letter grade and GPA
        switch (convertedScore)
        {
            case 0:
                cout << "Letter Grade: F\n";
                cout << "GPA: 0.0";
                break;
            case 1:
                cout << "Letter Grade: F\n";
                cout << "GPA: 0.0";
                break;
            case 2:
                cout << "Letter Grade: F\n";
                cout << "GPA: 0.0";
                break;
            case 3:
                cout << "Letter Grade: F\n";
                cout << "GPA: 0.0";
                break;
            case 4:
                cout << "Letter Grade: F\n";
                cout << "GPA: 0.0";
                break;
            case 5:
                cout << "Letter Grade: F\n";
                cout << "GPA: 0.0";
                break;
            case 6:
                cout << "Letter Grade: D\n";
                cout << "GPA: 1.0";
                break;
            case 7:
                cout << "Letter Grade: C\n";
                cout << "GPA: 2.0";
                break;
            case 8:
                cout << "Letter Grade: B\n";
                cout << "GPA: 3.0";
                break;
            case 9:
                cout << "Letter Grade: A\n";
                cout << "GPA: 4.0";
                break;
            case 10:
                cout << "Letter Grade: A\n";
                cout << "GPA: 4.0";
                break;
            default:
                cout << "This should never be displayed";
        }
    }
    else
    {
        // Output error message
        cout << "Error: Invalid Numerical Grade";
    }
    //Exit program
    return 0;
}
