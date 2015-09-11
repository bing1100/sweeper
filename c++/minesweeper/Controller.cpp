#include "Controller.h"
#include "View.h"
#include "TextDisplay.h"
#include <iostream>

/*
 * notifyView() : notify the view that there are updates
 * input : type - whether to call updateHint or update
 *         ch - char to update to
 *         h,w - coordinates of the square that is updated
 * output : void
 */
void Controller::notifyView(char type, char ch, int h, int w) {
	if (type == 'h') {
		tDisp->updateHint(h, w, ch);
	} else if (type == 'g') {
		tDisp->update(h, w, ch);
	}
}

/*
 * Controller() constructor
 */

Controller::Controller() {

}

/*
 * ~Controller() destructor
 */

Controller::~Controller() {

}

/*
 * Setup() : Setup a game or minesweeper
 */

void Controller::setup() {

	int h = 0;
	int w = 0;
	int b = -1;

	while (h == 0 && w == 0 && b == -1) {

		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << "| Welcome, Please setup your game of MineSweeper! |" << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;

		std::cout << "Input Height: ";
		if (!(std::cin >> h) || h <= 0) {
			std::cin.clear();
			std::cin.ignore();

			h = 0;
			w = 0;
			b = -1;

			std::cout << "Invalid height input! Please input natural number."<< std::endl;

			continue;
		}

		std::cout << "\nInput Width: ";
		if (!(std::cin >> w) || w <= 0) {
			std::cin.clear();
			std::cin.ignore();

			h = 0;
			w = 0;
			b = -1;

			std::cout << "Invalid Width input! Please input natural number."<< std::endl;

			continue;
		}

		std::cout << "\nInput number of bombs: ";
		if (!(std::cin >> b) || b < 0 || (b > h*w)) {
			std::cin.clear();
			std::cin.ignore();

			h = 0;
			w = 0;
			b = -1;

			std::cout << "Invalid Number if bombs! Please input natural number smaller size than of grid."<< std::endl;

			continue;
		}

	}

	tDisp = new TextDisplay(h, w);
	gBoard = new Board(this, h, w, b);

	numB = b;
	this->h = h;
	this->w = w;

	std::cout << "Starting the Game!" << std::endl;
	play();

}

void Controller::play() {

	tDisp->print("Welcome to the Game!", 'g');

	int counB = 0;

	while (!(counB == numB) || gBoard->anyWrong()) {

		int h = -1;
		int w = -1;
		char type = '-';

		while (h == -1 || w == -1 || !(type == 'c' || type == 'b' || type == 'C')) {
			std::cout << "Input Height Coordinate: ";
			if (!(std::cin >> h) || h < 0 || h > this->h) {
				std::cin.clear();
				std::cin.ignore();

				h = -1;
				w = -1;
				type = '-';

				std::cout << "Invalid height Coordinate"<< std::endl;

				tDisp->print("", 'g');

				continue;
			}

			std::cout << "\nInput Width Coordinate: ";
			if (!(std::cin >> w) || w < 0 || w > this->w) {
				std::cin.clear();
				std::cin.ignore();

				h = -1;
				w = -1;
				type = '-';

				std::cout << "Invalid height Coordinate"<< std::endl;

				tDisp->print("", 'g');

				continue;
			}

			std::cout << "\nInput Type of Click: ";
			if (!(std::cin >> type) || !(type == 'c' || type == 'b' || type == 'C')) {
				std::cin.clear();
				std::cin.ignore();

				h = -1;
				w = -1;
				type = '-';

				std::cout << "Input - 'c' for click on coord - 'b' to mark coord bomb - 'C' for cheatmode "<< std::endl;

				continue;
			}
		}

		if (type == 'C') {
			tDisp->print("X-Ray Vision Activated!", 'h');
		} else if (type == 'c') {
			if (!gBoard->updateSquare(h,w,'c')) {
				tDisp->print("Game Over, Please try Again :(", 'h');
				return;
			}

			tDisp->print("", 'g');

		} else {

			int code = gBoard->updateSquare(h,w,'b',counB);

			if (code == 2) {
				counB++;
				std::cout << "adding bomb" << std::endl;
				tDisp->print("", 'g');
			} else if (code == 3) {

				tDisp->print("Too many bombs", 'g');
			} else if (code == 4) {
				counB--;

				std::cout << "removing bomb" << std::endl;
				tDisp->print("", 'g');
			}


		}
	}


	tDisp->print("Congrats ! You Win!", 'h');

}
