/* 
 * File:   Square.h
 * Author: bhux
 *
 * Created on August 25, 2015, 10:45 PM
 */

#ifndef SQUARE_H
#define	SQUARE_H

class Square {
    
    // Coordinates of the Square
    int h;
    int w;
    
    // Important values of the square
    int value;
    bool marked;
    bool hidden;
    bool checked;
    
public:
    
    Square(int h, int w, int val); // Constructor
    ~Square(); // Destructor
    
    // Update the hidden boolean based on the given char value
    bool update(char val);
    
    
    // Getter/Setter
    bool getHidden();
    char getValue();
    bool getMarked();
    bool check();
    void unhide();
    bool isBomb();
    void incValue();
    void setBomb();
    
};

#endif	/* SQUARE_H */

