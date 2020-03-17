
#include <unistd.h>
#include <cstdint>
#include <iostream>
#include "terminal.h"
#include "canvas.h"

extern Screen screen;

void draw(int *nums, uint16_t size, int selectI, int compI, int mi) {
    // mi paramater is minimum or maximum index

    std::string s = "";
    // int colof = 20;
    //s += "\x1b[2J";

    setCursor(s, 1, 1);

    for (int i = 0; i < screen.rows; i++) {

	for (int j = 0; j < screen.cols; j++) {

	    int t = screen.rows - nums[j];

	    if (j < size && i > t-1) {

		if (j < selectI) {
		    // bright white
		    setColor(s, FG_BWHITE);	
		}
		else if (j == mi) {
		    // kind of purple
		    setColor(s, FG_BMAGNETA);	
		}
		else if (j == selectI) {
		    // kind of yellow
		    setColor(s, FG_BYELLOW);	
		}
		else if (j == compI) {
		    // light blue
		    setColor(s, FG_BBLUE);	
		}
		else {
		    // red color
		    setColor(s, FG_BRED);	
		}
		s +=  "▐";
	    } 	
	    else {
		s += " "; 
	    }
	}
    }
     
    // write the buffer to the standard output
    write(STDOUT_FILENO, s.c_str(), s.length());  

    // sleep in microseconds
    usleep(1000);

    #ifdef USE_TUT_MODE
	char c;
	read(STDIN_FILENO, &c, 1);
	if (c == 27)
	    exit(0);
    #endif
}

void draw_graph_canvas() {
    
    std::string str = "";
    // setColor(str, FG_BWHITE);
    for (int i = 0; i < screen.rows; i++) {
	for (int j = 0; j < screen.cols; j++) {
	    str += "\u25ae"; /* ▮ */
	}
    }
    write(STDOUT_FILENO, str.c_str(), str.length());
}


