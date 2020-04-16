/* Homework 29 */

/* 
 * File:    hw29.cpp
 * Author:  Christopher Garcia
 * Purpose: Read in a line of text and output the number of words in the 
 *          line and the number of occurrences of each letter
 * Date:    April 14, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Declare and Initialize Constants
const int AS = 26;


//----------------------------------------------------------------------------//


int main(int argc, char** argv)
{
    // Declare Variables
    int count[AS] = {0}, word = 1; 
    char alphabet[AS] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',\
                          'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string input;
    
    // Prompt for and read in text from user
    cout << "Enter a Line of Text: ";
    getline(cin, input);
    
    // Determine number of words
    for (int i =0; i<input.length(); i++)
    {                                
        if (isspace(input.at(i)))
        {            
            if (isalpha(input.at(i-1)) || input.at(i-1) =='.' \
                    || input.at(i-1) == ',')            
                ++word;           
        }
    }
    
    // Print number of words
    cout << "\nWords:    " << word;
    
    // Determine letter counts   
    for (int i =0; i<input.length(); i++)
    {
        if (input.at(i) == 'a' || input.at(i) == 'A')        
            count[0]++;
        else if (input.at(i) == 'b' || input.at(i) == 'B')        
            count[1]++;  
        else if (input.at(i) == 'c' || input.at(i) == 'C')        
            count[2]++;
        else if (input.at(i) == 'd' || input.at(i) == 'D')        
            count[3]++;
        else if (input.at(i) == 'e' || input.at(i) == 'E')        
            count[4]++;
        else if (input.at(i) == 'f' || input.at(i) == 'F')        
            count[5]++;
        else if (input.at(i) == 'g' || input.at(i) == 'G')        
            count[6]++;
        else if (input.at(i) == 'h' || input.at(i) == 'H')        
            count[7]++;
        else if (input.at(i) == 'i' || input.at(i) == 'I')        
            count[8]++;
        else if (input.at(i) == 'j' || input.at(i) == 'J')        
            count[9]++;
        else if (input.at(i) == 'k' || input.at(i) == 'K')        
            count[10]++;
        else if (input.at(i) == 'l' || input.at(i) == 'L')        
            count[11]++;
        else if (input.at(i) == 'm' || input.at(i) == 'M')        
            count[12]++;
        else if (input.at(i) == 'n' || input.at(i) == 'N')        
            count[13]++;
        else if (input.at(i) == 'o' || input.at(i) == 'O')        
            count[14]++;
        else if (input.at(i) == 'p' || input.at(i) == 'P')        
            count[15]++;
        else if (input.at(i) == 'q' || input.at(i) == 'Q')        
            count[16]++;
        else if (input.at(i) == 'r' || input.at(i) == 'R')        
            count[17]++;
        else if (input.at(i) == 's' || input.at(i) == 'S')        
            count[18]++;
        else if (input.at(i) == 't' || input.at(i) == 'T')        
            count[19]++;
        else if (input.at(i) == 'u' || input.at(i) == 'U')        
            count[20]++;
        else if (input.at(i) == 'v' || input.at(i) == 'V')        
            count[21]++;
        else if (input.at(i) == 'w' || input.at(i) == 'W')        
            count[22]++;
        else if (input.at(i) == 'x' || input.at(i) == 'X')        
            count[23]++;
        else if (input.at(i) == 'y' || input.at(i) == 'Y')        
            count[24]++;
        else if (input.at(i) == 'z' || input.at(i) == 'Z')        
            count[25]++;
    }
    
    // Print letter counts
    cout << "\nLetters:";
    for (int i = 0; i < AS; i++)
    {
        if (count[i] > 0)
            cout << "\n" << alphabet[i] << "    " << count[i];
    }
    
    // Exit Program    
    exit(EXIT_SUCCESS);
}
