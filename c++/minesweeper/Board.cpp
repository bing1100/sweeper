#include <stdlib.h>
#include <time.h>
#include "Board.h"
#include "Square.h"
#include "Controller.h"

/*
 * Constructor
 */

Board::Board(Controller * cont, int h, int w, int b): cont(cont), b(b), w(w), h(h) {

	/* initialize random seed: */
	srand (time(NULL));

	gArray = new Square**[h];

	for (int h_i =  0 ; h_i < h ; h_i++) {

		gArray[h_i] = new Square*[w];

		for (int w_i = 0 ; w_i < w ; w_i++) {
			gArray[h_i][w_i] = new Square(h,w,0);
		}

	}

	int bCount = 0;

	while (bCount < b) {

		// Generate a random h and w
		int c_h = rand() % h;
		int c_w = rand() % w;

		// Set the square to be a bomb, if it isnt already a bomb
		if(!gArray[c_h][c_w]->isBomb()) {

			gArray[c_h][c_w]->setBomb();
			bCount++;

			// Notify the view
			cont->notifyView('h','9',c_h, c_w);

			//Update the surrounding squares - Double switch mechanism
			for(int i = 0 ; i <= 4 ; i++) {

				// Double Switch mechanism sets the increment values
				int hInc = (i <= 2 ? -1 : 1);
				int wInc = (i % 2 == 0 ? -1 : 1);

				// Sets the working dimensions
				int wH = c_h + hInc;
				int wW = c_w + wInc;

				// Increment the value if can be incremented
				if ((0 <= wH && wH < h)
				  &&(0 <= wW && wW < w)) {

					gArray[wH][wW]->incValue();

					// Notify the view
					cont->notifyView('h', gArray[wH][wW]->getValue() ,c_h, c_w);
				}
			}
		}
	}
}

/*
 * Destructor
 */

Board::~Board() {

	for (int h_i =  0 ; h_i < h ; h_i++) {

		for (int w_i = 0 ; w_i < w ; w_i++) {

			delete gArray[h_i][w_i];

		}

		delete[] gArray[h_i];

	}

	delete[] gArray;

}

/*
 * updateSquare : Updates the square
 * input : h,w - the coordinates of the square
 * 	       ch - either 'b' (marking a bomb) or 'c' (clicking on the square)
 * output : returns false if the player clicks on a bomb that he did not mark as a bomb and true otherwise
 */

bool Board::updateSquare(int h, int w, char ch) {

	bool succ = gArray[h][w]->update(ch);

	if (ch == 'c') {

		if (succ && !gArray[h][w]->getMarked()) {

			notifyNeighbour(h,w);

		}

	}

	return succ || gArray[h][w]->getMarked();
}

/*
 * notifyNeighbour(h,w) : notify neighbours of [h][w] to unhide themselves if necessary
 */

void Board::notifyNeighbour(int h, int w) {

	gArray[h][w]->unhide();

	gArray[h][w]->check();

	cont->notifyView('g', gArray[h][w]->getValue(), h, w);

	if (gArray[h][w]->getValue() == '0'){
		//Update the surrounding squares - Double switch mechanism
		for(int i = 0 ; i <= 4 ; i++) {

			// Double Switch mechanism sets the increment values
			int hInc = (i <= 2 ? -1 : 1);
			int wInc = (i % 2 == 0 ? -1 : 1);

			// Sets the working dimensions
			int wH = h + hInc;
			int wW = w + wInc;

			// Increment the value if can be incremented
			if ((0 <= wH && wH < h)
			  &&(0 <= wW && wW < w)
			  &&(!gArray[wH][wW]->check())) {


				// Self Recursion
				notifyNeighbour(wH,wW);
			}
		}
	}
}
