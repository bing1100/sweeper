/* 
 * File:   Board.h
 * Author: bhux
 *
 * Created on August 25, 2015, 10:18 PM
 */

#ifndef BOARD_H
#define	BOARD_H

// Forward Declaration;
class Square;
class Controller;

class Board {

	// Dimensions of the board
	int h;
	int w;
    
    // Number of bombs
    int b;
    int nWrong;
    
    //Controller
    Controller * cont;
    
    // The game board
    Square *** gArray;
    
    // Helper function
    void notifyNeighbour(int h, int w);
    
public:

    Board(Controller * cont, int h, int w, int b); // Constructor
    ~Board(); // Destructor
    
    // Update the game Boards
    int updateSquare(int h, int w, char ch, int nb = 0);
    bool anyWrong();
    
};


#endif	/* BOARD_H */


