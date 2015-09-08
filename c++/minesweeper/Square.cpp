#include "Square.h"

/*
 * Constructor
 */

Square::Square(int h, int w, int val): h(h), w(w), value(val) {
	hidden = true;
	checked = false;
}

/*
 * Destructor
 */

Square::~Square() {

}

/*
 * getHidden : returns the value of hidden
 */

bool Square::getHidden() {
	return hidden;
}

/*
 * getMarked : returns the value of Marked
 */

bool Square::getMarked() {
	return marked;
}

/*
 * getValue : returns the char representation of value
 */

char Square::getValue() {
	return (char) value;
}

/*
 * isBomb() : returns true if the square is a bomb
 */

bool Square::isBomb() {
	return value == 9;
}

/*
 * setBomb() : set the square to be a bomb
 */

void Square::setBomb() {
	value = 9;
}

/*
 * incValue : increment the value of the square up to 8
 */

void Square::incValue() {
	if (value < 8) {
		value++;
	}
}

/*
 * update : main update function that controller uses to interact with the square
 * input : 0 - flip marked as bomb boolean
 * 		   1 - Click on this square
 * output : 0 - Successfully made the change
 *          1 - Clicked on a bomb
 */

bool Square::update(char val) {
	if (val == 'b') {
		marked = !marked;
	} else if (val == 'c') {

		if (value == 9) {
			return false;
		}

	}

	return true;
}

/*
 * unhide : sets the hidden variable to true
 */

void Square::unhide() {
	hidden = false;
}

/*
 * check() : returns the value of checked variable and set checked bool to true
 */

bool Square::check() {
	if (!checked) {
		checked = true;
		return false;
	}
	return true;
}
