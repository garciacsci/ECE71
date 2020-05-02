/* Homework hw40 */

/* 
 * File:    hw40.cpp
 * Author:  Christopher Garcia
 * Purpose: 
 * Date:    April 30, 2020
 */

////// Preprocessor Directives
#include <cstdlib> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// Name space
using namespace std;

// Structures
struct footBallPlayerType
{
    string name;
    string position;
    int touchdowns;
    int catches;
    int pass;
    int receive;
    int rush;        
};

// Declare and Initialize Constants
const int N=10;

//// Function Prototypes
// Display the menu
void showMenu();

//----------------------------------------------------------------------------//

// Get team data from the input file
void getData(ifstream &inputFile, footBallPlayerType list[N]);

//----------------------------------------------------------------------------//

// Save current team data to output file
void saveData(ofstream &outputFile, footBallPlayerType list[N]);

//----------------------------------------------------------------------------//

// Print entire team data to the screen
void printData(footBallPlayerType list[N]);

//----------------------------------------------------------------------------//

// Print a single player’s data to the screen
void printPlayerData(footBallPlayerType list[N], int playerNum);

//----------------------------------------------------------------------------//

// Search the data for a player
int searchData(footBallPlayerType list[N], string n);

//----------------------------------------------------------------------------//

// Update the number of touchdowns for a player
void updateTouchDowns(footBallPlayerType list[N],
int tDowns, int playerNum);

//----------------------------------------------------------------------------//

// Update the number of catches for a player 
void updateCatches(footBallPlayerType list[N], int catches,
int playerNum);

//----------------------------------------------------------------------------//

// Update the number of passing yards for a player
void updatePassingYards(footBallPlayerType list[N],
int passYards, int playerNum);

//----------------------------------------------------------------------------//

// Update the number of receiving yards for a player
void updateReceivingYards(footBallPlayerType list[N],
int recYards, int playerNum);

//----------------------------------------------------------------------------//

// Update the number of rushing yards for a player
void updateRushingYards(footBallPlayerType list[N],
int rushYards, int playerNum); 



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



int main(int argc, char** argv) 
{
    // Declare variables
    footBallPlayerType packers[N];
    int player,td,catches,pass,receive,rush,choice;
    char save;
    string name;
    ifstream fin;
    ofstream fout;
    
    // Open input file
    fin.open("PackersInput.txt");
    
    // Make sure input file opened properly
    if (fin.fail())
    {
        cout << "'PackersInput.txt' failed to open...";
        exit(EXIT_FAILURE);
    }
    
    // Get data from input file
    getData(fin, packers);

    // Open output file
    fout.open("PackersOutput.txt");
    
    // Make sure output file opened
    if(fout.fail())
    {
        cout << "'PackersOutput.txt' failed to open...";
        exit(EXIT_FAILURE);
    }
    
    // Enter loop to stay in interface until user chooses to exit
    do
    {
        // Print the menu and read in user choice
        showMenu();
        cin >> choice;
        cout << endl;
        
        // Read in information from user and call on function accordingly
        switch(choice)
        {
            case 1:
                // Print the team's data
                printData(packers);
                break;
                
            case 2:
                // Prompt for and read in player's name
                cout << "Enter player's name: ";
                cin >> name;
                cout << endl;
                
                // Find the player's index
                player = searchData(packers, name);
                
                // Print the player's data
                printPlayerData(packers, player);                
                break;
                
            case 3:
                // Prompt for and read in player's name
                cout << "Enter a player's name: ";
                cin >> name;
                cout << endl;
                
                // Find the player's index
                player = searchData(packers, name);
                
                // Prompt for new number of touchdowns
                cout << "Enter number of touchdowns to be added: ";
                cin >> td;
                cout << endl;
                
                // Update touchdowns for player
                updateTouchDowns(packers, td, player);
                break;
                
            case 4:
                // Prompt for and read in player's name
                cout << "Enter a player's name: ";
                cin >> name;
                cout << endl;
             
                // Find the player's index
                player = searchData(packers, name);
                
                // Prompt for and read in catches to add
                cout << "Enter number of catches to be added: ";
                cin >> catches;
                cout << endl;
                
                // Update catches for player
                updateCatches(packers, catches, player);
                break;
                
            case 5:
                // Prompt for and read in player's name
                cout << "Enter a player's name: ";
                cin >> name;
                cout << endl;
                
                // Find the player's index
                player = searchData(packers, name);
                
                // Prompt for and read in passing yards to add
                cout << "Enter number of passing yards to be added: ";
                cin >> pass;
                cout << endl;
                
                // Update passing yards for player
                updatePassingYards(packers, pass, player);
                break;
                                
            case 6:
                // Prompt for and read in player's name
                cout << "Enter a player's name: ";
                cin >> name;
                cout << endl;
                
                // Find the player's index
                player = searchData(packers, name);
                
                // Prompt for and read receiving yards to add
                cout << "Enter number of receiving yards to be added: ";
                cin >> receive;
                cout << endl;
                
                // Update receiving yards for player
                updateReceivingYards(packers, receive, player);
                break;
                
            case 7:
                // Prompt for and read in player's name
                cout << "Enter a player's name: ";
                cin >> name;
                cout << endl;
                
                // Find the player's index
                player = searchData(packers, name);
                
                // Prompt for and read in rushing yards to add
                cout << "Enter number of rushing yards to be added: ";
                cin >> rush;
                cout << endl;
                
                // Update catches for player
                updateRushingYards(packers, rush, player);
                break;
                
            case 99:
                break;
                
            default:
                cout << "Invalid selection.\n";      
                cout << endl;
                break;
        }
    } while(choice!=99);      
    
    cout << "Would you like to save data (Y/N): ";
    cin >> save;
    if(toupper(save) == 'Y')
        saveData(fout, packers);    
    else
        {
        // Close file
        fin.close();
        fout.close();          
        }        
    // Exit Program    
    exit(EXIT_SUCCESS);
}



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



//// Define User-Defined Functions

// Display the menu
void showMenu()
{
    // Print menu to screen
    cout << "Select one of the following options.\n";
    cout << "\t(1) Print the Team's Data\n";
    cout << "\t(2) Print a Player's Data\n";
    cout << "\t(3) Update a Player's Touchdowns\n";
    cout << "\t(4) Update a Player's Catches\n";
    cout << "\t(5) Update a Player's Passing Yards\n";
    cout << "\t(6) Update a Player's Receiving Yards\n";
    cout << "\t(7) Update a Player's Rushing Yards\n";
    cout << "\t(8) Quit the Program\n\n";
    cout << "Input Selection: ";

    // Exit Function
    return;
}

//----------------------------------------------------------------------------//

// Get team data from the input file
void getData(ifstream &inputFile, footBallPlayerType list[N])
{
    // Read in data from input file to structure array
    for (int i=0; i<N; i++)
    {
        inputFile >> list[i].name;
        inputFile >> list[i].position;
        inputFile >> list[i].touchdowns;
        inputFile >> list[i].catches;
        inputFile >> list[i].pass;
        inputFile >> list[i].receive;
        inputFile >> list[i].rush;        
    }

    // Exit Function
    return;
}

//----------------------------------------------------------------------------//

// Save current team data to output file
void saveData(ofstream &outputFile, footBallPlayerType list[N])
{    
    // Export data from structure array to output file
    for (int i=0; i<N; i++)
    {
        outputFile << list[i].name;
        outputFile << ' ';
        outputFile << list[i].position;
        outputFile << ' ';
        outputFile << list[i].touchdowns;
        outputFile << ' ';
        outputFile << list[i].catches;
        outputFile << ' ';
        outputFile << list[i].pass;
        outputFile << ' ';
        outputFile << list[i].receive;
        outputFile << ' ';
        outputFile << list[i].rush;        
        outputFile << endl;
    }
    
    // Exit Function
    return;
}

//----------------------------------------------------------------------------//

// Print entire team data to the screen
void printData(footBallPlayerType list[N])
{
    // Print header
    cout << "Name\t" << "Position " << "Touchdowns " << "Catches " << \
            "Passing " << "Receiving " << "Rushing\n";
    
    // Parse structure array and print to screen
    for (int i=0; i<N; i++)
    {
        cout << list[i].name;
        cout << setw(16-list[i].name.length()) << list[i].position;
        cout << setw(11) << list[i].touchdowns;
        cout << setw(8) << list[i].catches;
        cout << setw(8) << list[i].pass;
        cout << setw(10) << list[i].receive;
        cout << setw(8) << list[i].rush;
        cout << endl;
    }    

    cout << endl << endl;
    
    // Exit Function
    return;
}

//----------------------------------------------------------------------------//

// Print a single player’s data to the screen
void printPlayerData(footBallPlayerType list[N], int playerNum)
{   
    // Print Player stats to screen
        cout << "Name: " << list[playerNum].name << endl;
        cout << "  Position: " << list[playerNum].position << endl;
        cout << "  Touchdowns: " << list[playerNum].touchdowns << endl;
        cout << "  Number of Catches: " << list[playerNum].catches << endl;
        cout << "  Passing Yards: " << list[playerNum].pass << endl;
        cout << "  Receiving Yards: " << list[playerNum].receive << endl;
        cout << "  Rushing Yards: " << list[playerNum].rush << endl;        

    cout << endl << endl;    

    // Exit Function
    return;
}

//----------------------------------------------------------------------------//

// Search the data for a player
int searchData(footBallPlayerType list[N], string n)
{
    // Search for and return player index
    for (int i=0; i<N; i++)
    {
        if (list[i].name == n)
            return i;        
    }            
        
    // Return junk value
        return(-1);
}

//----------------------------------------------------------------------------//

// Update the number of touchdowns for a player
void updateTouchDowns(footBallPlayerType list[N],
int tDowns, int playerNum)
{
    // Check if playerNum is valid
    if (playerNum == -1)
        // Print invalid message if player is not found
        cout << "Invalid player number.\n\n";
    else
    {
    // Increment player's statistic appropriately
    list[playerNum].touchdowns+=tDowns;
    }
    
    cout << endl;
    
    // Exit Function
    return;
}

//----------------------------------------------------------------------------//

// Update the number of catches for a player 
void updateCatches(footBallPlayerType list[N], int catches,
int playerNum)
{
    // Check if playerNum is valid
    if (playerNum == -1)
        // Print invalid message if player is not found
        cout << "Invalid player number.\n\n";
    else
    {
    // Increment player's statistic appropriately
    list[playerNum].catches+=catches;
    }
    
    cout << endl;
    
    // Exit Function
    return;
}

//----------------------------------------------------------------------------//

// Update the number of passing yards for a player
void updatePassingYards(footBallPlayerType list[N],
int passYards, int playerNum)
{
    // Check if playerNum is valid
    if (playerNum == -1)
        // Print invalid message if player is not found
        cout << "Invalid player number.\n\n";
    else
    {
    // Increment player's statistic appropriately
    list[playerNum].pass+=passYards;
    }
    
    cout << endl;
    
    // Exit Function
    return;
}

//----------------------------------------------------------------------------//

// Update the number of receiving yards for a player
void updateReceivingYards(footBallPlayerType list[N],
int recYards, int playerNum)
{
    // Check if playerNum is valid
    if (playerNum == -1)
        // Print invalid message if player is not found
        cout << "Invalid player number.\n\n";
    else
    {
    // Increment player's statistic appropriately
    list[playerNum].receive+=recYards;
    }
    
    cout << endl;
    
    // Exit Function
    return;
}

//----------------------------------------------------------------------------//

// Update the number of rushing yards for a player
void updateRushingYards(footBallPlayerType list[N],
int rushYards, int playerNum)
{
    // Check if playerNum is valid
    if (playerNum == -1)
        // Print invalid message if player is not found
        cout << "Invalid player number.\n\n";
    else
    {
    // Increment player's statistic appropriately
    list[playerNum].rush+=rushYards;
    }
    
    cout << endl;
    
    // Exit Function
    return;
}
