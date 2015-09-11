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
		
		for (int w_i = 0 ; w_i < w ; w_i++) {

			board[h_i][w_i] = '-';
			hint[h_i][w_i] = '-';

		}

	}
}

/*
 * View Destructor
 */
View::~View() {
	
	for (int h_i = 0 ; h_i < h ; h_i++) {
			
			
			delete[] board[h_i];
			delete[] hint[h_i];
			
		}
	
	delete[] board;
	delete[] hint;

}

/*
 * Update(): updates the board object
 * input : h,w coordinates
 *         ch - char to update to
 * output : void
 */
void View::update(int h, int w, char ch) {

	board[h][w] = ch;

}

/*
 * UpdateHint(): updates the hint object
 * input : h,w coordinates
 *         ch - char to update to
 * output : void
 */
void View::updateHint(int h, int w, char ch) {

	hint[h][w] = ch;

}
