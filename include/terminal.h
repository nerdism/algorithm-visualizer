#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>
#include <cstdint>

/* For Ground Bright Color */
#define FG_BMAGNETA	95  /* i call this color pink */
#define FG_BBLUE	96  /* it's like sky blue */
#define FG_BWHITE	97
#define FG_BRED		91
#define FG_BYELLOW	93

#define FG_DEFAULT	39

/* terminal infos */
struct Screen {
    uint16_t rows;
    uint16_t cols;
};

void setCursorPosition	    (std::string &s, int x, int y);

void setCursor		    (std::string &s, int x, int y);

void cleanScreen	    (std::string &s);

/**
 * this set ansi color code to the given string
 * 
 * @Param s
 *  a string which is gonna be printed in the screen
 * 
 * @Param color ex 96
 *  96 is the ansi code for light blue (bright cyan)
 */

void setColor		    (std::string &s, int color);

/**
 * getting the terminal size
 *
 * @Param rows
 *  number of the terminal rows
 *  setting this inside the function 
 *
 * @Param cols
 *  number of the terminal columns
 *  setting this inside the function
 *  
 */
void getWindowSize(uint16_t *rows, uint16_t *cols) ;

void enableTerminalRawMode  ();

void disableTerminalRawMode ();

#endif
