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
    
    char ** board;
    char ** hint;
    
public:
    View();  // Constructor
    virtual ~View() = 0; // Destructor
    
    // Methods for game board
    void update (int h , int w , char ch);
    void print (std::string msg);
    
    // Methods for hint board
    void updateHint (int h , int w , char ch);
    void printHint (std::string msg);
        
};

#endif	/* VIEW_H */

