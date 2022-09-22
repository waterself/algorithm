#include "insertSort.h"
#include <random>
void arraySwap(int* in, int a, int b) {
	int tmp = in[a];
	in[a] = in[b];
	in[b] = tmp;
}

bool SortCheck(int* array, int size) {
	bool sorted = true;
	for (int i = 0; i < size - 1; i++) {
		if (array[i] > array[i + 1]) {
			sorted = false;
			break;
		}
	}
	return sorted;
}

int* MakeRandomArray(int size) {
	int* output = new int[size];
	for (int i = 0; i < size; i++) {
		output[i] = rand() % size;
	}
	return output;
}
