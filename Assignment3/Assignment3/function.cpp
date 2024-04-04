#include "function.h"
#include <vector>

//recursive linear search function that finds the last occurrence of a target

int linear_search(vector<int>& items, int target, int pos_last) {
	if (pos_last < 0)
		return -1;
	if (target == items[pos_last])
		return pos_last;
	else
		return linear_search(items, target, pos_last - 1);
}