/* Homework hw32 */

/* 
 * File:    hw32.cpp
 * Author:  Christopher Garcia
 * Purpose: Print three integer values from the user in ascending order
 *          using pointers
 * Date:    April 22, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <iostream>

using namespace std;

// Function Prototypes
void ptrSort(int *a, int *b, int *c);
//sort the numbers so that x contains the smallest number, y
//contains the middle number, and z contains the largest number

//----------------------------------------------------------------------------//

int main(int argc, char** argv) 
{
    // Declare variables
    int x,y,z,*i=&x,*j=&y,*k=&z;
    
    // Prompt for and read in variables from user
    cout << "Please enter the first number: ";
    cin >> *i;
    cout << "Please enter the second number: ";
    cin >> *j;
    cout << "Please enter the third number: ";
    cin >> *k;
    
    // Sort numbers
    ptrSort(i,j,k);
    
    // Print numbers in order
    cout << "\nThe sorted numbers are: " << *i << ", " << *j << ", and " << *k \
            << ".";


    // Exit Program    
    exit(EXIT_SUCCESS);
}


//----------------------------------------------------------------------------//

// Define User-Defined Functions
void ptrSort(int *a, int *b, int *c)
{
    // Declare variables
    int *temp = new int;
    
    // Sort numbers
    
    // If a is the smallest
    if (*a<*b && *a<*c)
    {
        // If b is middle
        if (*b<*c)
        {
            delete temp;
            return;
        }
        // If c is middle
        else
        {
            //swap b and c
            *temp=*b;
            *b=*c;
            *c=*temp;
            delete temp;
            return;
        }
    }
    // If b is smallest
    else if (*b<*a && *b<*c)
    {        
        // make a smallest by swapping a and b
        *temp=*a;
        *a=*b;
        *b=*temp; 
        
        // If b is middle
        if(*b<*c)
        {
            delete temp;
            return;            
        }
        // If c is middle
        else
        {                       
            *temp=*c;
            *c=*b;
            *b=*temp;
            delete temp;
            return;
        }
    }
    // If c is smallest
    else
    {
        // make a smallest
        *temp=*a;
        *a=*c;
        *c=*temp;
        
        // if b is middle
        if(*b<*c)
        {
            delete temp;
            return;
        }
        
        // If c is middle
        else
        {            
            *temp=*b;
            *b=*c;
            *c=*temp;
            delete temp;
            return;
        }
    }
}
