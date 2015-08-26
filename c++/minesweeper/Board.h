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
    
    // Number of bombs
    int b;
    
    //Controller
    Controller cont;
    
    // The game board
    Square *** gArray;
    
    // Helper function
    void notifyNeighbour(int h, int w, bool r, char type);
    
public:
    
    Board(Controller cont, int h, int w, int b); // Constructor
    ~Board(); // Destructor
    
    // Update the two game Boards
    void updateSquare(int h, int w, char ch);
    void updateHint();
    void setup();
    
    
    
};


#endif	/* BOARD_H */


