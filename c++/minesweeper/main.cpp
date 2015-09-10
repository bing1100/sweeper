/* 
 * File:   main.cpp
 * Author: bhux
 *
 * Created on August 25, 2015, 4:21 PM
 */

#include <cstdlib>

#include "Controller.h"
#include "Board.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

	Controller * cont = new Controller;

	cont->setup();

    return 0;
}

