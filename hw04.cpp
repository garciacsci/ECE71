/* Homework 4*/

/* 
 * Name:    hw04.cpp
 * Purpose: Determine how many months it will take to pay off a loan and the total amount of interest paid over the life of the loan.
 * Author:  Christopher Garcia
 * Date:    3 February 2020
 */

// Preprocessor Directives
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

// Define Constants
const double IR = .015;
const double MP = 50;

// Main Function
int main(int argc, char** argv) 
{
//Declare Variables
    int monthsPassed;
    double debt, interestPayment, loanPayment, remainingLoan, totalInterestPayment;

// Initialize Variables
    monthsPassed = 0;
    debt = 1000;  
    totalInterestPayment = 0;
    
// Setting output to fixed notation, show decimal point, and always show two places 
       cout.setf(ios::fixed);
       cout.setf(ios::showpoint);
       cout.precision(2);
    
//Create Loop
    do
    {  
        // Month Header
        cout << "Month " << ++monthsPassed << endl;
        
        // Interest Payment
        interestPayment = (IR * debt);
        cout << "Interest Payment:\t" << "$" << setw(6) << interestPayment << endl;
        
        // Loan Payment
        loanPayment = (MP - interestPayment);
        cout << "Loan Payment:\t" << "\t" << "$" << setw(6) << loanPayment << endl;
        
        // Remaining Loan
        remainingLoan = debt -= loanPayment;
        cout << "Remaining Loan: \t" << "$" << setw(6) << remainingLoan << endl;
        
        // Total Interest Payment
       totalInterestPayment += interestPayment;
       
        // Break
       cout << "\n";
        
    } while (debt > 0);
    
    // Months to Pay Off
    cout << "The loan will take " << monthsPassed << " months to pay off." << endl;
    
    // Total Interest Payments
    cout << "The total interest payments are $" << totalInterestPayment << "." << endl;
    
    // Exit Program
    return 0;
}
