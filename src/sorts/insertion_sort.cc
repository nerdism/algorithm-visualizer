
#include "canvas.h"
#include "sorts/insertion_sort.h"
#include <algorithm>


void insertion_sort(int *nums, int size) {
    for (int i = 1; i < size; i++) {

	int j = i-1, item = nums[i];
	while (j > -1 && item < nums[j]) {
	    draw(nums, size, i, j);
	    nums[j+1] = nums[j];
	    --j;
	}

	nums[j+1] = item;
    }
}


