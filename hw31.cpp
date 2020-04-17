/* Homework hw31 */

/* 
 * File:    hw31.cpp
 * Author:  Christopher Garcia
 * Purpose: 
 * Date:    April 15, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Declare and Initialize Constants


// Function Prototypes

// getContact() checks to see if the current line of the file is the start 
// of a contact and returns it if it is
bool checkForContact(string current);

// checkForPalmdale checks to see if the current contact is in Palmdale and
// stores the line number of the contact if they do
bool checkForPalmdale(string current);


// checkForZip checks to see if the current contact is in a valid zip and
// stores the line number of the contact if they are
bool checkForZip(string current);


// If a valid contact is found:

// getName() extracts the contact name from the file
// and pushes it to a string vector
 void getName(ifstream &fin, vector<string> &name);
   
// getStreet() extracts the street and pushes it to a string vector
 void getStreet(ifstream &fin, vector<string> &street);  
 
// getCity() extracts the city and pushes it to a string vector
 void getCity(ifstream &fin, vector<string> &city);
 
// getState() extracts the state and pushes it to a string vector
 void getState(ifstream &fin, vector<string> &state);
 
// getZip() extracts the zip code and pushes it to a string vector
 void getZip(ifstream &fin, vector<string> &zip); 

 
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//


int main(int argc, char** argv) 
{
    // Declare Variables
    ifstream fin;
    string check, contact;
    int line, count=0, contactTally=0, i=0, pSize;
    vector<string> name, street, city, state, zip;
    vector<int> pLine, zLine;
    
    // Open Files
    fin.open("address.xml");
    
    // Exit if address.xml failed to open
     if (fin.fail())
    {
        cout << "'Address.xml' failed to open...\n";
        exit(EXIT_FAILURE);
    }

    getline(fin,check); 
    
    // Parse the file for Palmdale Contacts and contacts in valid zips and 
    // log what line they're on
    do
    {
        if (checkForContact(check))
            line = count;
        if (checkForPalmdale(check))
            pLine.push_back(line);
        if (checkForZip(check))
            zLine.push_back(line);
        
        getline(fin, check);
        count++;
    } while (!fin.eof());
    
    count = 0;
    getline(fin, check);
    
    do
    {
        if (count == pLine[i])
        {                        
            getName(fin, name);
            
            getStreet(fin,street);
                      
            getCity(fin, city);             
            
            getState(fin, state);
            
            getZip(fin, zip);  
            
            i++;
        } while (!fin.eof());
        
        
        pSize = (pLine.size());
        
    // Print Palmdale Addresses
    cout << "Palmdale Addresses\n";
    
    for (i=0; i < pSize; i++)
        cout << "\n\t" << name[i] << "\n\t" << street[i] << \
                city[i] << ", " << state[i] << " " << zip[i];
        
        count=0;
        i=0;
        getline(fin,check);         
                                                               
    } while (!fin.eof());           
    
    // Close files
    fin.close();
        
    // Exit Program    
    exit(EXIT_SUCCESS);
}


//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//


// Define User-Defined Functions
bool checkForContact(string current)
{
    // Declare variables
    string dummy;
    int begin, length;
    
    // Look for contact tag
    begin = current.find("<contact>");    
    length = 9;
    
    dummy = (current.substr(begin,length));
    
    // Check if contact tag is on the current line and return appropriate value    
    if (dummy == "<contact>")
        return(true);
    else
        return(false);    
}

//----------------------------------------------------------------------------//

bool checkForPalmdale(string current)
{
    // Declare variables
    int begin, length;
    
    // Look for contact tag
    begin = current.find("Palmdale");    
    length = 8;
    
    // Check if contact tag is on the current line and return appropriate value      
    if ((current.substr(begin,length)) == "Palmdale")
        return(true);
    else
        return(false);    
}

//----------------------------------------------------------------------------//

bool checkForZip(string current)
{
    // Declare variables
    string dummy;
    int begin, end, length;
    
    // Look for contact tag
    begin = current.find("<zip>");    
    begin+=5;
    end = current.find("</name>");
    length = end-begin;
    
    // Check if contact tag is on the current line and return appropriate value     
    if ((current.substr(begin,length)) >= "90210" && \
            (current.substr(begin,length))<= "90214")
        return(true);
    else
        return(false);    
}

//----------------------------------------------------------------------------//

void getName(ifstream &fin, vector<string> &name)
{
    // Declare variables
    string dummy;
    int begin, end, length;
    
    // Find start and length of name
    begin = dummy.find("<name>");
    begin+=6;
    end = dummy.find("</name>");
    length = end-begin;
    
    // Stick the name into the name vector
    name.push_back(dummy.substr(begin,length));    
    
    // Exit Function
    return;
}

//----------------------------------------------------------------------------//


void getStreet(ifstream &fin, vector<string> &street)
{
    // Declare variables
    string dummy;
    int begin, end, length;
    
    // Find start and length of name
    begin = dummy.find("<street>");
    begin+=8;
    end = dummy.find("</street>");
    length = end-begin;
    
    // Stick the name into the name vector
    street.push_back(dummy.substr(begin,length));

    // Exit Function
    return;
}

//----------------------------------------------------------------------------//


void getCity(ifstream &fin, vector<string> &city)
{
    // Declare variables
    string dummy;
    int begin, end, length;
    
    // Find start and length of name
    begin = dummy.find("<city>");
    begin+=6;
    end = dummy.find("</city>");
    length = end-begin;
    
    // Stick the name into the name vector
    city.push_back(dummy.substr(begin,length));

    // Exit Function
    return;
}

//----------------------------------------------------------------------------//


void getState(ifstream &fin, vector<string> &state)
{
    // Declare variables
    string dummy;
    int begin, end, length;
    
    // Find start and length of name
    begin = dummy.find("<state>");
    begin+=7;
    end = dummy.find("</state>");
    length = end-begin;
    
    // Stick the name into the name vector
    state.push_back(dummy.substr(begin,length));

    // Exit Function
    return;
}

//----------------------------------------------------------------------------//


void getZip(ifstream &fin, vector<string> &zip)
{
    // Declare variables
    string dummy;
    int begin, end, length;
    
    // Find start and length of name
    begin = dummy.find("<zip>");
    begin+=5;
    end = dummy.find("</zip>");
    length = end-begin;
    
    // Stick the name into the name vector
    zip.push_back(dummy.substr(begin,length));

    // Exit Function
    return;
}
