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

// Function Prototypes

// getContact() checks to see if the current line of the file is the start 
// of a contact and returns it if it is
bool checkForContact(ifstream &fin);

// checkForPalmdale checks to see if the current contact is in Palmdale and
// stores the line number of the contact if they do
bool checkForPalmdale(vector<string> city, int index);


// checkForZip checks to see if the current contact is in a valid zip and
// stores the line number of the contact if they are
bool checkForZip(vector<string> zip, int index);


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
    string check;
    int line=0, count, i;
    vector<string> name, street, city, state, zip;
    
    // Open File
    fin.open("address.xml");
    
    // Exit if address.xml failed to open
     if (fin.fail())
    {
        cout << "'Address.xml' failed to open...\n";
        exit(EXIT_FAILURE);
    }

     
    
    // Extract Contact information from file into appropriate vectors  
    count=0;
    do
    {
        if (checkForContact(fin))
        {            
            getName(fin, name);
            count++;

            getStreet(fin, street);
            count++;
            
            getCity(fin, city);             
            count++;
            
            getState(fin, state);
            count++;
            
            getZip(fin, zip);  
            count++;                        
        }
    } while (!fin.eof());
    
    
    // Print Palmdale Contacts
    cout << "Palmdale Addresses";    
    for (i=0; i<name.size(); i++)
    {
        if (checkForPalmdale(city, i))
        {
            cout << "\n\n\t" << name[i] << "\n\t" << street[i] << "\n\t" << \
                    city[i] << ", " << state[i] << "  " << zip[i];                                                                                
        }
    }
    // Print Zip Contacts
    cout <<"\n\nAdvertising to [90210-90214]";
    
    for (i=0; i<name.size(); i++)
    {
        if (checkForZip(zip, i))
            {
                cout << "\n\n\t" << name[i] << "\n\t" << street[i] << "\n\t" \
                        << city[i] << ", " << state[i] << "  " << zip[i];                                                                                
            }        
    }
    // Close File
    fin.close();
    
    // Exit Program    
    exit(EXIT_SUCCESS);
}


//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//


// Define User-Defined Functions
bool checkForContact(ifstream &fin)
{
    // Declare variables
    string dummy;
    int begin, end, length;
    
    getline(fin,dummy);
    
    // Look for contact tag
    begin = dummy.find("<");    
    begin++;
    end = dummy.find(">");    
    length = end - begin;    
    
    dummy=(dummy.substr(begin,length));
    
    // Check if contact tag is on the current line and return appropriate value    
    if (dummy == "contact")
        return(true);
    else
        return(false);    
}

//----------------------------------------------------------------------------//

bool checkForPalmdale(vector<string> city, int index)
{    
    // Check if Palmdale is the current city      
    if (city[index] == "Palmdale")
        return(true);
    else
        return(false);    
}

//----------------------------------------------------------------------------//

bool checkForZip(vector<string> zip, int index)
{        
    // Check if current zip is valid
    if (zip[index] == "90210" || zip[index] == "90211" || \
            zip[index] == "90212" || zip[index] == "90213" || \
            zip[index] == "90214")
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
    
    getline(fin, dummy);
    
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
    
    getline(fin, dummy);
    
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
    
    getline(fin, dummy);
    
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
    
    getline(fin, dummy);
    
    // Find start and length of name
    begin = dummy.find("<state>");
    begin+=7;
    end = dummy.find("</state>");
    length = (end-begin);
        
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
    
    getline(fin, dummy);
    
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
