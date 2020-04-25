/* Homework hw34 */

/* 
 * File:    hw34.cpp
 * Author:  Christopher Garcia
 * Purpose: Read a message and see if it's a palindrome.
 * Date:    April 22, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <cstring>

using namespace std;

// Declare and Initialize Constants
const int N=101;

// Function Prototypes
bool isPalindrome(char *cstr);
// Checks to see if the message is a palindrome
// Precondition: *cstr points to the beginning of a character array
// that contains all characters entered by the user



//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//



int main(int argc, char** argv) 
{
    // Declare variables
    char message[N]={'\0'};
    int c,i=0;
    
    // Prompt for and read in message
    cout << "Enter a message: ";
    while (i<N && c!='\n')
    {
        c=getchar();        
        message[i]=c;
        i++;
    }

    // Check if the message is a palindrome and print result
    if(isPalindrome(message))    
        cout << "The line is a palindrome.";
    else
        cout << "The line is not a palindrome.";
      
    // Exit Program    
    exit(EXIT_SUCCESS);
}



//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//



// Define User-Defined Functions
bool isPalindrome(char *cstr)
{
    // Declare and initialize variables
    char *front = cstr;
    char *back = cstr+strlen(cstr)-1;
    //Parse message
    while (front<back)
        {
            // Check if the two sides of the message "mirror" each other
            // check that both "sides" are letters
            if (isalpha(*front) && isalpha(*back))
                // If they're the same move the pointers
                if (toupper(*front) == toupper(*back)) 
                {
                    if (front < cstr+strlen(cstr)-1)
                        front++;
                    if (back >= cstr)
                    back--;
                }                        
                // If they're not, return false
                else
                    return(false);
            // if they're not, find which one isn't and move its pointer
            else if (!isalpha(*front) && cstr+strlen(cstr)-1)
                front++;
            else if (!isalpha(*back) && back >= cstr)
                back--;
        }
    // If the whole message checks out, return true
    return (true);
} 
