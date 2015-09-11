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

			gArray[c_h][c_w]->setBomb();
			bCount++;

			// Notify the view
			cont->notifyView('h','9',c_h, c_w);

			//Update the surrounding squares - Double switch mechanism
			for(int hInc = -1 ; hInc <= 1 ; hInc++) {
				for (int wInc = -1 ; wInc <= 1 ; wInc++) {

					// Sets the working dimensions
					int wH = c_h + hInc;
					int wW = c_w + wInc;

					// Increment the value if can be incremented
					if ((0 <= wH && wH < h)
					  &&(0 <= wW && wW < w)) {

						gArray[wH][wW]->incValue();

						// Notify the view
						cont->notifyView('h', gArray[wH][wW]->getValue() ,wH, wW);
					}
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

		if (!gArray[h][w]->getMarked() && gArray[h][w]->getHidden()) {

			succ = gArray[h][w]->update(ch);

			if (succ) {

				notifyNeighbour(h,w);


			}
		}

		return  gArray[h][w]->getMarked() || !gArray[h][w]->getHidden();

	} else {
		if (!gArray[h][w]->getMarked() && nb < b && gArray[h][w]->getHidden()) {

			std::cout << "return 2" << std::endl;


			gArray[h][w]->update(ch);


			if (!gArray[h][w]->isBomb()) {
				nWrong++;
			}

			cont->notifyView('g', '9', h, w);

			return 2;
		} else if (!gArray[h][w]->getMarked() && gArray[h][w]->getHidden()){

			std::cout << "return 3" << std::endl;

			return 3;
		} else if (gArray[h][w]->getHidden()) {

			std::cout << "return 4a" << std::endl;

			gArray[h][w]->update(ch);

			std::cout << "return 4aa" << std::endl;

			if (!gArray[h][w]->isBomb()) {
				nWrong--;
			}

			std::cout << "return 4aaa" << std::endl;
			cont->notifyView('g', '-', h, w);
			std::cout << "return 4aaaa" << std::endl;
			return 4;
		} else {
			return 0;
		}
	}

	return succ;
}

/*
 * notifyNeighbour(h,w) : notify neighbours of [h][w] to unhide themselves if necessary
 */

void Board::notifyNeighbour(int h, int w) {

	std::cout << "called for : " << h << " " << w << " " <<gArray[h][w]->getValue()  << std::endl;

	gArray[h][w]->unhide();

	gArray[h][w]->check();

	cont->notifyView('g', gArray[h][w]->getValue(), h, w);

	if (gArray[h][w]->getValue() == '0'){
		//Update the surrounding squares - Double switch mechanism
		for(int hInc = -1 ; hInc <= 1 ; hInc++) {
			for (int wInc = -1 ; wInc <= 1 ; wInc++) {

				// Sets the working dimensions
				int wH = h + hInc;
				int wW = w + wInc;

				// Increment the value if can be incremented
				if ((0 <= wH && wH < this->h)
				  &&(0 <= wW && wW < this->w)
				  &&(!gArray[wH][wW]->check())) {

					// Self Recursion
					notifyNeighbour(wH,wW);
				}
			}
		}
	}
}

bool Board::anyWrong() {
	return nWrong != 0;
}
