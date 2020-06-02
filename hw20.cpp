/* Homework 20*/

/* 
 * File:    hw20.cpp
 * Purpose: Merge numbers from two files and write all the numbers into a
 *          third file in ascending order
 * Author:  Christopher Garcia
 * Date:    March 18, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function Prototypes
void checkFailure(ifstream &fin1, ifstream &fin2, ofstream &fout);
// Checks to see if files opened successfully

void sortNumbers(ifstream &fin1, ifstream &fin2, ofstream &fout); 
// sorts the numbers from two files in ascending order
// precondition: files must be open

// Define Main Function

int main(int argc, char** argv) 
{
    // Declare Variables
    ifstream fin1, fin2;
    ofstream fout;
    
    // Open Files
    fin1.open("numbers1.txt");
    fin2.open("numbers2.txt");
    fout.open("sorted.txt");
    
    // Call check failure function
    checkFailure(fin1, fin2, fout);
    
    // Call sort numbers function
    sortNumbers(fin1, fin2, fout);
    
    // Close Files
    fin1.close();
    fin2.close();
    fout.close();

    // Exit Program
    exit(EXIT_SUCCESS);
}

// Define User Defined Functions
void checkFailure(ifstream &fin1, ifstream &fin2, ofstream &fout)
{
    // Check to see if any of the files failed to open
    if (fin1.fail())
    {
        cout << "'Numbers1.txt' failed to open...\n";
        exit(EXIT_FAILURE);
    }
    else if (fin2.fail())
    {
        cout << "'Numbers2.txt' failed to open...\n";
        exit(EXIT_FAILURE);
    }
    else if (fout.fail())
    {
        cout << "'Sorted.txt' failed to open...\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        // Exit Function
        return;
    }
}
void sortNumbers(ifstream &fin1, ifstream &fin2, ofstream &fout)
{
    // Declare and initialize Variables
    double n1, n2;
    int tally = 1;
    
    // Set precision, show decimal, and set fixed notation for outputs
    cout.setf(ios::fixed);
    fout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    fout.setf(ios::showpoint);
    cout.precision(8);
    fout.precision(8);
    
    // Read in and store a value from each file
    fin1 >> n1;
    fin2 >> n2;
    
    // Sort numbers until the end of a file is hit
    do
    {
        // Compare number from each file & output minimum
        if (n1 < n2)
        {
            cout << setw(3) << tally << "\t" << n1 << "\n";
            fout << setw(3) << tally << "\t" << n1 << "\n";
            fin1 >> n1;
        }
        else
        {
            cout << setw(3) << tally << "\t" << n2 << "\n";
            fout << setw(3) << tally << "\t" << n2 << "\n";
            fin2 >> n2;
        }
        
        // Increment tally
        tally++;
        
    } while (!fin1.eof() && !fin2.eof());
    
    // Determine which file is at its end and continue sorting accordingly
    if (fin1.eof() && !fin2.eof())
    {
        // output value stored from file that didn't end and continue \
            outputting values from said file until end of file is reached
        while (!fin2.eof())
        {
            cout << setw(3) << tally << "\t" << n2 << "\n";
            fout << setw(3) << tally << "\t" << n2 << "\n";
            fin2 >> n2;
            tally++;
        }
    }
    else if (!fin1.eof() && fin2.eof())
    {
        // output value stored from file that didn't end and continue \
            outputting values from said file until end of file is reached
        while (!fin1.eof())
        {
            cout << setw(3) << tally << "\t" << n1 << "\n";
            fout << setw(3) << tally << "\t" << n1 << "\n";
            fin2 >> n1;
            tally++;
        }
    }
    else
        // Hopefully this never shows up
        cout << "Something wacky happened after the end of one of the files \
                    was hit...";
    
    // Exit Function
    return;
}
