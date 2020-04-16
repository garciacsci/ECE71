/* Homework 30 */

/* 
 * File:    hw30.cpp
 * Author:  Christopher Garcia
 * Purpose: Read a person’s name in the following format: first name, middle 
 *          name or middle initial, and last name then returns their last, 
 *          first (middle initial.)
 * Date:    April 15, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <iomanip>

using namespace std;


//----------------------------------------------------------------------------//

int main(int argc, char** argv) 
{
    // Declare Variables
    string full, first, middle, last;
    int name=1, p1=0, p2=0, p3=0;
    
    // Prompt user for and read in name
    cout << "Enter a name: ";
    getline(cin, full);
    
    // Parse input
    for (int i =0; i<full.length(); i++)
    {                                
        if (isspace(full.at(i)) || full.at(i) == '.')
        {            
            if (isalpha(full.at(i-1)))            
            {
                ++name;
                if (p1 == 0)
                    p1=i+1;
                else if (p2 == 0)
                {
                    if (full.at(i) == '.')
                    p2 = i+2;
                    else
                    p2 = i+1;
                }
                else if (p3 == 0)
                    p3 = i+1;
            } 
        }
    }
    
    // Print name accordingly
    cout << "Abbreviation: ";
    first = full.substr(0,p1-1);
    if (name == 2)
    {
        last = full.substr(p1,p2-p1);
        cout << last << ", " << first;
    }
    else if (name == 3)
    {
        middle = full.substr(p1,1);
        last = full.substr(p2,p3-p2);
        cout << last << ", " << first << " " << middle << ".";
    }    
    
    // Exit Program    
    exit(EXIT_SUCCESS);
}
