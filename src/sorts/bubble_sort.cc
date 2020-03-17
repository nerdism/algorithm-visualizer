
#include "canvas.h"
#include "sorts/insertion_sort.h"
#include <algorithm>

void bubble_sort_v1(int *nums, int size) {
    

    int i = 0, j;
    for (i = 0; i < size; i++) {

	for (j = size-1; j > i ; j--) {
	    draw(nums, size, i, j);
	    if (nums[j] < nums[j-1]) {
		std::swap(nums[j], nums[j-1]);	 
	    }	
	}
    }
    draw(nums, size, i, j);
}

void bubble_sort_v2(int *nums, int size) {

    int i=0, j=0;
    for (i = size-1; i > 0; i--) {

	for (j = 0; j < i ; j++) {

	    draw(nums, size, i, j);
	    if (nums[j] > nums[j+1]) {
		std::swap(nums[j], nums[j+1]);	 
	    }	

	}
    }

    draw(nums, size, i);
}
