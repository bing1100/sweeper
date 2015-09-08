#include "View.h"


/*
 * View(): Constructor
 * input: h: Height
 * 		  w: Width
 * output: None
 *  		  	
 */
View::View(int h, int w): h(h), w(w) {
	

	board = new char*[h];
	hint = new char*[h];
	
	for (int h_i = 0 ; h_i < h ; h_i++) {
		
		
		board[h_i] = new char[w];
		hint[h_i] = new char[w];
		
	}
}

View::~View() {
	
	for (int h_i = 0 ; h_i < h ; h_i++) {
			
			
			delete[] board[h_i];
			delete[] hint[h_i];
			
		}
	
	delete[] board;
	delete[] hint;

}
