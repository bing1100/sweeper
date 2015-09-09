/* 
 * Project: minesweeper
 * File:   View.h
 * Author: bhux
 *
 * Created on August 25, 2015, 5:26 PM
 */

#ifndef VIEW_H
#define	VIEW_H

#include <string>

class View {

public:

	int h;
	int w;

	char ** board;
	char ** hint;
    
    View(int h, int w);  // Constructor
    virtual ~View() = 0; // Destructor
    

    // Methods for game board
    void update (int h , int w , char ch);
    
    // Methods for hint board
    void updateHint (int h , int w , char ch);

    // Printer
    virtual void print (std::string msg, char type) = 0;
        
};

#endif	/* VIEW_H */

