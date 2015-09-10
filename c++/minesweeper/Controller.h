/* 
 * File:   Controller.h
 * Author: bhux
 *
 * Created on August 25, 2015, 5:46 PM
 */

#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include "Board.h"
#include "View.h"
#include "TextDisplay.h"

class Controller {


	int numB;
	int h;
	int w;
    Board * gBoard;
    TextDisplay * tDisp;
    
public:
    
    Controller(); // Constructor
    ~Controller(); // Destructor
    
    void notifyView(char type, char ch, int h, int w);
    void displayHint();
    void play();
    void setup();
    
};

#endif	/* CONTROLLER_H */

