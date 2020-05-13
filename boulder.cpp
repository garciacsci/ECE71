/* Contains all “boulder” class member function definitions */

// Include header files
#include "init.hpp"
#include "boulder.hpp"

//// Function definitions
/// Boulder member function definitions
// Default Constructor
 Boulder::Boulder()
 {
    // Generate Boulder
    gameInfo.board[rand()%(NROWS-2)+1][rand()%(NCOLS-2)+1] = -10;
    
    // Exit function
    return;
 }

 // Constructor with color initialization
 Boulder::Boulder(int c)
 {
    // REVISIT FOR COLOR

    // Generate Boulder
    gameInfo.board[rand()%(NROWS-2)+1][rand()%(NCOLS-2)+1] = -10;

   // Exit function
   return;

 }

 // Function to help create a new apple
 void Boulder::newBoulder(int c)
 {
     
    // REVISIT FOR COLOR
     
    // Generate Boulder
    gameInfo.board[rand()%(NROWS-2)+1][rand()%(NCOLS-2)+1] = -10;

     // Exit function
     return;
 }
 
 // Clears boulders from the board
    void clearBoulder()
    {
    // Declare Variables
        int row=0, column=1;
    
    // Parse board array and clear boulders
        while (column<NCOLS-1)
        {
            for (row=1; row<NROWS-1; row++)
            {
                if (gameInfo.board[row][column] == -10)
                    gameInfo.board[row][column] = 0;
            }
        column++;
        }
    }
