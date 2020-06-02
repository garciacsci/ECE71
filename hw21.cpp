/* Homework 21*/

/* 
 * File:    hw21.cpp
 * Purpose: Compute the average word length for a file that contains some text
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
void wordLength(ifstream &bob);
// Calculates the average characters per word in bob.txt
// Precondition: File must be open

// Define Main Function
int main(int argc, char** argv)
{
    // Declare Variables
    ifstream bob;
    
    // Open Bob
    bob.open("bob.txt");
    
    // Check if bob failed to open
    if (bob.fail())
    {
        cout << "'bob.txt' failed to open...";
        exit(EXIT_FAILURE);
    }
    else
    {
        // Call on wordLength function
        wordLength(bob);
    }
    
    // Close files
    bob.close();

    // Exit Program
    exit(EXIT_SUCCESS);
}

// Define User Defined Functions
void wordLength(ifstream &bob)
{
    // Declare Variables
    char cChar, pChar;
    int cCount = 0, wCount = 0;
    
    // Read in first character of file
    bob >> cChar;
    
    // Increment character count appropriately
    if (isalpha(cChar))
    cCount++;    
    
    // Determine word and character count for rest of file
    while (!bob.eof())
    {   
        // Print out current character and file stats
        cout << "\n" << cChar << "\tChars: " << cCount << "\t" << "Words: " \
             << wCount;
            
        // update current and previous character variables
        pChar = cChar;
        bob.get(cChar);
        
        // Evaluate current character and update stats accordingly
        if (isspace(cChar))
        {            
            if (!isspace(pChar) && pChar != '-')
            {
                wCount++;
            }           
        }
        else if (isalpha(cChar))
        {
            cCount++;
        }
        else if ((cChar == '-' || cChar == '\'')  && isalpha(pChar))
        {                
            cCount++;
        }                
    }
    
    // Format output
    cout.setf(ios::fixed);  
    cout.setf(ios::showpoint);    
    cout.precision(2);
        
    // Calculate and print Average chars/word                    
    cout << "\n\n\tAverage Chars/Word: " << static_cast<double>(cCount)/wCount;
    
    // Exit Function
    return;
}
