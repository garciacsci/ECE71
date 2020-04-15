/* Homework 28 */

/* 
 * File:    hw28.cpp
 * Author:  Christopher Garcia
 * Purpose: Translate an alphabetic phone number into numeric form using 
 *          C-based character arrays 
 * Date:    April 14, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// Declare and Initialize Constants
const int N = 15;


//----------------------------------------------------------------------------//



int main(int argc, char** argv) 
{
    // Declare Variables
    char original[N+1] = {'\0'}, translation[N+1] = {'\0'};
    
    // Prompt User for phone number
    cout << "Enter Phone Number:\t";
    
    // Store Phone number
    cin >> original;
    
    // Copy to Translation array
    int index=0;
    while (original[index] != '\0' && index < N)
    {   
        translation[index] = original[index];          
        index++;
    }            
    
    // Translate Phone number
    for (int i=0; i<N; i++)
        {             
            if (translation[i] == '.' || translation[i] == ',' || \
                translation[i] == '@')
                    translation[i] = '1';
            else if (translation[i] == 'a' || translation[i] == 'A' || \
                    translation[i] == 'b' || translation[i] == 'B' || \
                    translation[i] == 'c' || translation[i] == 'C')
                translation[i] = '2';
            else if (translation[i] == 'd' || translation[i] == 'D' || \
                    translation[i] == 'e' || translation[i] == 'E' || \
                    translation[i] == 'f' || translation[i] == 'F')
                translation[i] = '3';
            else if (translation[i] == 'g' || translation[i] == 'G' || \
                    translation[i] == 'h' || translation[i] == 'H' || \
                    translation[i] == 'i' || translation[i] == 'I')
                translation[i] = '4';
            else if (translation[i] == 'j' || translation[i] == 'J' || \
                    translation[i] == 'k' || translation[i] == 'K' || \
                    translation[i] == 'l' || translation[i] == 'L')
                translation[i] = '5';
            else if (translation[i] == 'm' || translation[i] == 'M' || \
                    translation[i] == 'n' || translation[i] == 'N' || \
                    translation[i] == 'o' || translation[i] == 'O')
                translation[i] = '6';
            else if (translation[i] == 'p' || translation[i] == 'P' || \
                    translation[i] == 'q' || translation[i] == 'Q' || \
                    translation[i] == 'r' || translation[i] == 'R' || \
                    translation[i] == 's' || translation[i] == 'S')
                translation[i] = '7';
            else if (translation[i] == 't' || translation[i] == 'T' || \
                    translation[i] == 'u' || translation[i] == 'U' || \
                    translation[i] == 'v' || translation[i] == 'V')
                translation[i] = '8';
            else if ( translation[i] == 'w' || translation[i] == 'W' || \
                    translation[i] == 'x' || translation[i] == 'X' || \
                    translation[i] == 'y' || translation[i] == 'Y' || \
                    translation[i] == 'z' || translation[i] == 'Z')
                translation[i] = '9';                                
        }      
    
    // Print translation
    cout << "Numeric Form:\t\t";
    for (int i =0; i<strlen(original) && i < N; i++)
        cout << translation[i];
    
    // Exit Program
    exit(EXIT_SUCCESS);
}
