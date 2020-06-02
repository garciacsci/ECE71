/* Homework 22*/

/* 
 * File:    hw22.cpp
 * Purpose: Number the lines found in a text file and keep track of the
 *          character statistics of the file
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
void fileParser(ifstream &file);
// calculates all the necessary stats of the file while printing them out
// Precondition: file is open

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
        // Call on fileParser function
        fileParser(bob);
    }
    
    // Close files
    bob.close();

    // Exit Program
    exit(EXIT_SUCCESS);
}

// Define User Defined Functions
void fileParser(ifstream &file)
{
    // Declare and initialize Variables
    int line = 1, paragraph = 0, word = 0, character = 0, \
            alpha = 0, nonAlpha= 0, whiteSpace = 0;
    char current, previous;
    
    // Read in first character of file
    file.get(current);
    
    cout << line << ": ";
                
    // Determine word and character count for rest of file while printing
    while (!file.eof())
    {   
        // Print out current character and file stats
        if (previous == '\n')
        {
            // Print line and character
            cout << line << ": ";              
        }                
            // Print character
            cout << current;                                                                     
        
        // Evaluate current character and update stats accordingly
        if (isspace(current))
        {           
            whiteSpace++;
            if (!isspace(previous) && previous != '-')
            {
                word++;
            }          
            if (current == '\n')
            {
                line++;
                if (previous == '\n')
                    paragraph++;
            }
        }
        else if (isalpha(current))
        {
            alpha++;
        } 
        else
            nonAlpha++;
        
        // update current and previous character variables
        previous = current;
        file.get(current);
    }
    // Account for carryover line and calculate character count
    --line;
    character = (alpha + nonAlpha + whiteSpace);
    
    // Output stats
    cout << "\n\nParagraph Count: \t" << setw(3) << paragraph
            << "\nLine Count: \t\t" << setw (3) << line
            << "\nWord Count: \t\t" << setw(3) << word
            << "\nCharacter Count: \t" << setw(3) << character
            << "\nAlpha Character Count: \t" << setw(3) << alpha
            << "\nNon-Alpha Count: \t" << setw(3) << nonAlpha
            << "\nWhiteSpace Count: \t" << setw(3) << whiteSpace;
    
    
    // Exit Function
    return;
}
