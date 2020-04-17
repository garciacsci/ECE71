
// preprocessor directives
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

bool checkForContact(string current);


// main function 
int main(int argc, char** argv) 
{
    // declare variable
    ifstream fin;
    string dummy("test");
    vector<string>xml;
    int line=0, count=0;
    
    fin.open("address.xml");
    
    if (fin.fail())
    {
        cout << "'address.xml' failed to open...\n";
        exit(EXIT_FAILURE);
    }
    
    do
    {
        if (checkForContact(dummy))
            line = count;
        
        getline(fin, dummy);
        count++;
    } while (!fin.eof());
    

    
    exit (EXIT_SUCCESS);
}


////////////////////////////////////////////////////////////////////////////////

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
