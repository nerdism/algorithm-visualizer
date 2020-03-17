#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <time.h>
#include "vsignal.h"
#include "terminal.h"
#include <cstdio>
#include <signal.h>
#include "sorts/selection_sort.h"
#include "sorts/insertion_sort.h"
#include "sorts/bubble_sort.h"
#include "sorts/merge_sort.h"
#include "canvas.h"

int show_options();

extern Screen screen;

int main() {
    
    register_signal(SIGINT, sigint_handler);
    int opt = show_options(); 

    #ifdef USE_TUT_MODE
	enableTerminalRawMode();
    #endif

    // turn off cursor display
    write(STDOUT_FILENO, "\x1b[?25l", 6);

    srand(time(NULL));

    getWindowSize(&screen.rows, &screen.cols);

    // array size related to the screen columns
    int size = screen.cols;

    
    // make array of numbers
    int* nums = new int[size];

    for (int i = 0; i < size; i++) {

	// make random number but maximum number has 5 less character
	// for not reaching the top the screen
	nums[i] = (rand() % (screen.rows - 5)) + 1;
    }

    switch (opt) {
	case 1:
	    selection_sort(nums, size);
	    break;
	case 2:
	    bubble_sort_v1(nums, size);
	    break;
	case 3:
	    bubble_sort_v2(nums, size);
	    break;
	
	case 4:
	    insertion_sort(nums, size);
	    break;
	
	case 5:
	    merge_sort(nums, 0, size-1);
	    break;
    
	case 6:
	    draw_graph_canvas();
	    break;
	default:
	    std::cout << "Wrong number!!" << std::endl;
	    exit(1);
	    break;
    }

    // turn off cursor display
    write(STDOUT_FILENO, "\x1b[?25h", 6);
    
    // char c;
    // read(STDIN_FILENO, &c, 1);
    /* for (int i = 0; i < size; i++) { */
	/* std::cout << nums[i] << " "; */
    /* } */

    delete [] nums;

    return 0;
}

int show_options() {
    int opt = 0;
    std::cout << "choose a option\n"  << std::endl;
    std::cout << "1.selection sort\n" << std::endl;
    std::cout << "2.bubble sort v1\n" << std::endl;
    std::cout << "3.bubble sort v2\n" << std::endl;
    std::cout << "4.insertion sort\n" << std::endl;
    std::cout << "5.merge sort\n"     << std::endl;
    std::cout << "6.bfs (breadth first search)\n"     << std::endl;

    
    std::cin >> opt;

    return opt;
}


