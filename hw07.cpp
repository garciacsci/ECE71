/* Homework 7*/

/* 
 * Name:    hw07.cpp
 * Purpose: Convert a U.S dollar amount into 20, 10, 5, and 1 dollar units.
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
    // Declare Variables
    int dollarAmount, twenty, ten, five, one;
    char response;
    
    // Enter do while loop
    do
    {
        //Prompt for and read in dollar amount
        cout << "Enter a dollar amount: ";
        cin >> dollarAmount;
        cout << "\n";
                
        // Break dollar amount into units
        twenty = dollarAmount/20;
        dollarAmount = dollarAmount%20;
        ten = dollarAmount/10;
        dollarAmount = dollarAmount%10;
        five = dollarAmount/5;
        dollarAmount = dollarAmount%5;
        one = dollarAmount/1;
        
        // Print out results
        cout << "$" << setw(3) << "20 " << "bills: " << twenty << "\n";
        cout << "$" << setw(3) << "10 " << "bills: " << ten << "\n";
        cout << "$" << setw(3) << "5 " << "bills: " << five << "\n";
        cout << "$" << setw(3) << "1 " << "bills: " << one << "\n\n";

        cout << "Convert another dollar amount? (Y/N): "; 
        cin >> response;
    } while (response == 'Y' || response == 'y');
    
    // Exit Program
    return 0;
}
