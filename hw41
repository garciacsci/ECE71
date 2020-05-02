/* Homework hw41 */

/* 
 * File:    hw41.cpp
 * Author:  Christopher Garcia
 * Purpose: Tic-Tac-Toe
 * Date:    April 30, 2020
 */

////// Preprocessor Directives
#include <cstdlib> 
#include <iostream>
#include <iomanip>

// Namespace
using namespace std;

// Enumerated Data Types
enum status {WIN, DRAW, CONTINUE};


// Declare classes
class TicTacToe
{
// Declare public functions/variables
public:
    //// Function Prototypes
    void play();
    // Function to play the game

    //------------------------------------------------------------------------//

    void displayBoard() const;
    // Function to print the board

    //------------------------------------------------------------------------//

    bool isValidMove(int row, int col) const;
    // Function to determine if a move is valid

    //------------------------------------------------------------------------//

    bool getMove(char moveSymbol);
    // Function to get a move for a player    

    //------------------------------------------------------------------------//

    status gameStatus();
    // Function to determine the current status of the game
    // Uses the status enumeration data type for members WIN,
    // DRAW, and CONTINUE

    //------------------------------------------------------------------------//

    void restart();
    // Function to restart the game
    // Postcondition: Brings the board back to an empty state
    
    //------------------------------------------------------------------------//
    
    TicTacToe();
    // Default constructor 
    // Postcondition: Brings the board back to an empty state
    
    //------------------------------------------------------------------------//
    
// Declare private functions/variables
private:
    char board[3][3];
    int moves;
};



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////// Define main function
int main(int argc, char** argv) 
{
    // Declare Variables
    TicTacToe ttt;
    char choice;
    
    // Continue playing the game until the user wants to stop
    do
    {
        // Restart the game
        ttt.restart();
        
        // Play the game
        ttt.play();
        
        // See if the player wants to play again
        cout << "Play Again (Y/N)?: ";
        cin >> choice;
        
    } while (toupper(choice)=='Y');

    // Exit Program    
    exit(EXIT_SUCCESS);
}



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



////// Define User-Defined Functions
void TicTacToe::play()
{
    // Declare variables
    bool done = false;
    char player = 'X';
            
    while(!done)
    {
        // show the board
        displayBoard();
        
        // Move the current player
        done = getMove(player);
        
        // Swap to other player
        if(player == 'X')
        {
            player = 'O';
        }
        else 
        {
            player = 'X';
        }
    }
    // Exit Function
    return;
}

//----------------------------------------------------------------------------//

void TicTacToe::displayBoard() const
{
    // Declare variables    
    int row=0, col=0;
    
    // Clear the screen
    system("clear");
    
    // Print header
    cout << "     Tic-Tac-Tow Game" << endl;
    cout << endl;
    
    // Print board with plays
    cout << "         1   2   3" << endl;
    cout << "           |   |  " << endl;
    cout << "      1  "<< board[0][0] << " | " << board[0][1] << " | " << \
                            board[0][2] << endl;
    cout << "        ___|___|___" << endl;
    cout << "           |   |  " << endl;
    cout << "      2  " << board[1][0] << " | " << board[1][1] << " | " << \
                            board[1][2] << endl;
    cout << "        ___|___|___" << endl;
    cout << "           |   |  " << endl;
    cout << "      3  " << board[2][0] << " | " << board[2][1] << " | " << \
                            board[2][2] << endl;
    cout << "           |   |  " << endl;
                                                  
    cout << endl;
        
    // Exit Function
    return;
}

//----------------------------------------------------------------------------//


bool TicTacToe::isValidMove(int row, int col) const
{
    // Check to make sure move is in range and empty; return appropriate value
    if((row>=0 && row<=2) && (col>=0 && col<=2) && board[row][col]==' ')
        return true;
    else
        return false;
}

//----------------------------------------------------------------------------//

bool TicTacToe::getMove(char moveSymbol)
{
    // Declare variables
    int row, col;
    bool valid;
    status gameState;
    
    // So long as the current move isn't a valid one, continue to...
    do
    {
        // Prompt for and read in current player's move
        cout << "Player " << moveSymbol;
        cout << " Enter Move: ";
        cin >> row >> col;
        
        // Check if move is valid
        valid = isValidMove(row-1,col-1);
        
        // If it is
        if (!valid)
        {
            // Tell the player if the move is invalid
            cout << "Invalid move\n";
        }
        cout << '\n';
    } while(!valid);
    
    // Decrement row & col to account for element location syntax
    row--;
    col--;
    
    // Increment number of moves
    moves++;
    
    // Place current player's symbol on the board
    board[row][col] = moveSymbol;
    
    // Show the board
    displayBoard();
    
    // Get the game status
    gameState = gameStatus();
    
    // Check if the game is over
    if(gameState == WIN)
    {
        cout << "Player " << moveSymbol << " wins!\n";
        return true;
    }
    else if(gameState == DRAW)
    {
        cout << "The game is a draw!\n";
        return true;
    }
    else
        return false;    
}

//----------------------------------------------------------------------------//

status TicTacToe::gameStatus()
{            
    // Check rows
    for (int row=0; row<3; row++)   
    {
        if (board[row][0]!=' ' && (board[row][0]==board[row][1] && \
                board[row][1]==board[row][2]))
        {
            return(WIN);    
        }
    }
    
    // Check columns
    for (int col=0; col<3; col++)
    {
      if (board[0][col] != ' ' && (board[0][col]==board[1][col] &&\
              board[1][col]==board[2][col]))
      {
          return(WIN);    
      }
    }
    // Check diagonals
    if (board[0][0]!=' ' && (board[0][0]==board[1][1] &&\
            board[1][1]==board[2][2]))
        return(WIN);
    
    if (board[0][2]!=' ' && (board[0][2]==board[1][1] &&\
            board[1][1]==board[2][0]))
        return(WIN);
    
    // If maximum number of moves haven't been hit, return continue
    if (moves<9)
        return(CONTINUE);
    
    // Return draw if nobody won
    return(DRAW);
}

//----------------------------------------------------------------------------//

void TicTacToe::restart()
{
    // Initialize board to ' '
    for (int row=0; row<3; row++)
        for (int col=0; col<3; col++)
            board[row][col]=' ';
    
    // Set number of moves to 0
    moves=0;    

    // Exit Function
    return;
}

//----------------------------------------------------------------------------//

TicTacToe::TicTacToe()
{
    // Initialize board to ' '
    for (int row=0; row<3; row++)
        for (int col=0; col<3; col++)
            board[row][col]=' ';
    
    // Set number of moves to 0
    moves=0;
}
