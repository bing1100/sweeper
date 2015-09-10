#include "View.h"
#include "TextDisplay.h"
#include <string>
#include <iostream>

TextDisplay::TextDisplay(int h, int w): View(h,w) {

}

TextDisplay::~TextDisplay(){

}

/*
 * print() : prints either the hint or board object to terminal
 * input : msg - a message to print
 * 		   type - dictates whether to print board or hint
 * output : void
 */

void TextDisplay::print(std::string msg, char type) {

	char *** pObject = &(type == 'h' ? hint : board);


	// Print the width size on top
	std::cout << " ";
	for (int w_i = 0 ; w_i < w ; w_i++) {

		std::cout << w_i;

	}

	std::cout << std::endl;

	// Print the rest of the table
	for (int h_i = 0 ; h_i < h ; h_i++) {

		// Print the height labels
		std::cout << h_i;

		for (int w_i = 0 ; w_i < w ; w_i++) {

			std::cout << (*pObject)[h_i][w_i];

		}

		std::cout << std::endl;

	}

	std::cout << std::endl;

	//Print the ending message
	std::cout << msg << std::endl;
}
