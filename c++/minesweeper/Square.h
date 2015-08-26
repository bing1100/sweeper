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
    bool hidden;
    int moveCounter;
    
public:
    
    Square(int h, int w, int val); // Constructor
    ~Square(); // Destructor
    
    // Update the hidden boolean based on the given char value
    bool update(char ch);
    
    
    // Getter/Setter
    bool getHidden();
    bool isBomb();
    void setValue(char val);
    
};

#endif	/* SQUARE_H */

