/* Homework hw35 */

/* 
 * File:    hw35.cpp
 * Author:  Christopher Garcia
 * Purpose: Use functions that use dynamic arrays to emulate
 *          the behavior of a vector
 * Date:    April 22, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Declare and Initialize Constants


// Function Prototypes
string* addEntry(string *dynamicArray, int &size, string newEntry);
// Adds a string to array
// Precondition: Pointer points to an initialized string array, size is
// accurate, and newEntry is a string

//----------------------------------------------------------------------------//

string* deleteEntry(string *dynamicArray, int &size, string entryToDelete);
// Deletes a string from array
// Precondition: Pointer points to an initialized string array, size is
// accurate, and entryToDelete is a valid string

//----------------------------------------------------------------------------//

void output(string *dynamicArray, int size);
// Prints out array
// Precondition: array is initialized and size is accurate



//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//



int main(int argc, char** argv) 
{
    // Declare Variables
    int size=5;
    string *p = new string[size]{"Gregory","Bobby","Helen","Raylan","Ava"};
    string add, del;   
    
    // 1. Print array
    cout << "Output 1:";
    output(p,size);    
    
    
    // 2. Add Kristin to array
    add="Kristin";
    p= addEntry(p,size,add);    
    
    // 3. Print the array
    cout << "\n\nOutput 2:";
    output(p,size);
    
    // 4. Delete Greg from the array
    del = "Greg";
    p= deleteEntry(p,size,del);
    
    // 5. Print the array
    cout << "\n\nOutput 3:";
    output(p,size);
    
    // 6. Delete Gregory from the array
    del="Gregory";
    p= deleteEntry(p,size,del);
    
    // 7. Print the array
    cout << "\n\nOutput 4:";
    output(p,size);
    
    // 8. Delete Kristin from the array
    del="Kristin";
    p=deleteEntry(p,size,del);
    
    // 9. Print the array
    cout << "\n\nOutput 5:";
    output(p,size);
    
    // 10. Delete Helen from the array
    del="Helen";
    p=deleteEntry(p,size,del);
    
    // 11. Print the Array
    cout << "\n\nOutput 6:";
    output(p,size);
    
    // Exit Program    
    exit(EXIT_SUCCESS);
}



//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//



// Define User-Defined Functions
string* addEntry(string *dynamicArray, int &size, string newEntry)
{
    // Declare variables    
    string *nda = new string[size+1];    
    
    // Copy old array into new array
    for(int i=0; i<size; i++)
    {
        nda[i] = dynamicArray[i]; 
    }
    
    // Add new entry to array
    nda[size]=newEntry;
    
    // Update size
    size++;
    
    // Delete old array
    delete [] dynamicArray;
    
    // Return new array
    return(nda);
}

//----------------------------------------------------------------------------//


string* deleteEntry(string *dynamicArray, int &size, string entryToDelete)
{    
    // Search for entry to delete
    for(int i=0; i<size; i++)
    {        
        if (dynamicArray[i] == entryToDelete)
        {
            // Create new dynamic array
            string *nda = new string[size-1];      
            // Create separate index for smaller array
            int index=0;
            // Copy old array - entryToDelete into new array
            for(int i=0; i<size; i++)
            {
                if(dynamicArray[i] != entryToDelete)
                {
                    nda[index] = dynamicArray[i]; 
                    index++;
                }
            }
            // Delete old array
            delete [] dynamicArray;
            
            // Update size
            size--;
            
            // Return new dynamic array
            return(nda);
        }
    }
    
    // Return unmodified array if entry to delte is not found
    return(dynamicArray);                                   
}

//----------------------------------------------------------------------------//


void output(string *dynamicArray, int size)
{
    // Print elements
    for (int i=0; i<size; i++)    
        cout << endl << dynamicArray[i];

    // Exit Function
    return;
}
