/* 
 * Project: {license=default, encoding=UTF-8, licensePath=/Templates/Licenses/license-default.txt}
 * File:   TextDisplay.h
 * Author: bhux
 *
 * Created on August 25, 2015, 5:35 PM
 */

#ifndef TEXTDISPLAY_H
#define	TEXTDISPLAY_H

#include <string>
#include "View.h"

class TextDisplay: public View {
    public:
        TextDisplay(int h, int w);
        ~TextDisplay();

        // Printer
        void print (std::string msg, char type);
};

#endif	/* TEXTDISPLAY_H */

