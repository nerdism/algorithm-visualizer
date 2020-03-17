
#include "canvas.h"
#include "sorts/selection_sort.h"
#include <algorithm>

// selection sort algorithm
void selection_sort(int *nums, int size) {
    int i, j, mi;
    for (i = 0; i < size - 1; i++) {
	mi = i;	
	for (j = i + 1; j < size; j++) {
	    draw(nums, size, i, j, mi);
	    if (nums[j] < nums[mi]) {
		mi = j;
	    }	
	}
	std::swap(nums[i], nums[mi]);
    }   
    draw(nums, size, i+1, j, mi);
}



