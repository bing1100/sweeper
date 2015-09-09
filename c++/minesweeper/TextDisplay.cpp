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

	for (int h_i = 0 ; h_i < h ; h_i++) {
		for (int w_i = 0 ; w_i < w ; w_i++) {

			std::cout << (*pObject)[h_i][w_i];

		}

		std::cout << std::endl;

	}

	std::cout << msg << std::endl;
}
