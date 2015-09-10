#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Board.h"
#include "Square.h"
#include "Controller.h"

/*
 * Constructor
 */

Board::Board(Controller * cont, int h, int w, int b): cont(cont), b(b), w(w), h(h), nWrong(0) {

	/* initialize random seed: */
	srand (time(NULL));

	std::cout << "-1" << std::endl;

	gArray = new Square**[h];

	std::cout << "-2" << std::endl;

	for (int h_i =  0 ; h_i < h ; h_i++) {

		gArray[h_i] = new Square*[w];

		for (int w_i = 0 ; w_i < w ; w_i++) {
			gArray[h_i][w_i] = new Square(h,w,0);
		}

	}

	int bCount = 0;

	std::cout << "Bomb" << std::endl;

	while (bCount < b) {

		// Generate a random h and w
		int c_h = rand() % h;
		int c_w = rand() % w;

		std::cout << c_h << " " << c_w << std::endl;

		// Set the square to be a bomb, if it isnt already a bomb
		if(!gArray[c_h][c_w]->isBomb()) {

			std::cout << "Make it a bomb" << std::endl;

			gArray[c_h][c_w]->setBomb();
			bCount++;

			std::cout << "Made it a bomb" << std::endl;

			// Notify the view
			cont->notifyView('h','9',c_h, c_w);

			std::cout << "Notified View" << std::endl;

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

int Board::updateSquare(int h, int w, char ch, int nb) {


	bool succ = false;

	if (ch == 'c' ) {

		if (!gArray[h][w]->getMarked()) {

			succ = gArray[h][w]->update(ch);

			if (succ) {

				notifyNeighbour(h,w);

			}
		}

		return  gArray[h][w]->getMarked() || succ;

	} else {
		if (!gArray[h][w]->getMarked() && nb < b) {

			gArray[h][w]->update(ch);

			if (!gArray[h][w]->isBomb()) {
				nWrong++;
			}

			cont->notifyView('g', '9', h, w);

			return 2;
		} else if (!gArray[h][w]->getMarked()){

			return 3;
		} else {

			gArray[h][w]->update(ch);

			if (!gArray[h][w]->isBomb()) {
				nWrong--;
			}

			cont->notifyView('g', '0', h, w);
			return 4;
		}
	}

	return succ;
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

bool Board::anyWrong() {
	return nWrong != 0;
}
