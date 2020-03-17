
#include "canvas.h"
#include "sorts/merge_sort.h"
#include "terminal.h"
#include <algorithm>

extern Screen screen;

void merge_sort(int *nums, int begin, int end) {
    
    if (begin == end) {
	return ; 
    }
    else {
	int mid = (begin + end) / 2;
	merge_sort(nums, begin, mid); 
	merge_sort(nums, mid+1, end);

	merge_two(nums, begin, mid, end);
    }

}

void merge_two(int *nums, int begin, int mid, int end) {

    int i = begin, j = mid+1, c = 0;

    // new array size
    int size = end+1 - begin;
    int *ptr = new int[size];

    while (i <= mid && j <= end) {
	if (nums[i] < nums[j]) 
	    ptr[c] = nums[i++];
	else 
	    ptr[c] = nums[j++];
	c++;
    }

    while (i < mid+1) {
	ptr[c++] = nums[i++]; 
    }

    while (j < end+1) {
	ptr[c++] = nums[j++]; 
    }

    j = 0;
    for (i=begin; i < end+1; i++) {
	nums[i] = ptr[j++];
	draw(nums, screen.cols, i, j);
    }

    delete [] ptr;

}

