/* Homework 3*/

/* 
 * Name:    hw03.cpp
 * Purpose: Calculate how many chocolate bars you need to eat to maintain your 
 *          weight
 * Author:  Christopher Garcia
 * Date:    1 February 2020
 */

// Preprocessor Directives
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

// Define Constants
const int BAR = 230; 
const int IPF = 12;

// Main Function
int main(int argc, char** argv)
{
    // Declare Variables
    int weight, height, feet, inches, age, rubbish;
    double bmr, cbn;
    char sex;
    
    // Prompt for weight in lbs.
    cout << "Enter your weight in lbs: ";
    cin >> weight;
    
    // Prompt for height in feet & inches
    cout << "Enter your height in feet and inches: ";
    cin >> feet;
    cin >> inches;
    
    // Prompt for age
    cout << "Enter your age: ";
    cin >> age;
    
    // Prompt for Sex
    cout << "Enter your sex (M/F): ";
    cin >> sex;
    
    // Calculate height in inches
    height = IPF * feet + inches;
    
    // Calculate BMR
    if (sex == 'M' || sex == 'm')
    {
        bmr = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
    }
    else
    {
        bmr = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
    }
    
    // Calculate Chocolate Bars Needed (cbn)
    cbn = bmr/BAR;
    
    // Print Result
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "\n";
    cout << "Your BMR is " << bmr << "calories." << endl;
    cout << "If a chocolate bar contains " << BAR << " calories," << endl;
    cout << "you need to eat " << cbn << " chocolate bars to maintain your weight. ";
    
    // Exit Program
    return 0;
}
