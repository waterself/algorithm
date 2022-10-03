#include <iostream>
#include "HeapSort.h"
using namespace std;

void MaxHeapfy(int* array, int first, int size) {
	int currenNode = first;

	int leftChild = currenNode * 2;
	int rightChild = currenNode * 2 + 1;

	if (leftChild < size) {
		if (array[currenNode] < array[leftChild]) {
			currenNode = leftChild;
		}
	}
	if (rightChild < size) {
		if (array[currenNode] < array[rightChild]) {
			currenNode = rightChild;
		}
	}
	if (currenNode != first) {
		arraySwap(array, currenNode, first);
		MaxHeapfy(array, currenNode, size);
	}
}

void BuildMaxHeap(int* array, int size) {
	int parentNode;

	for (parentNode = size / 2 - 1; parentNode >= 0; parentNode--) {
		MaxHeapfy(array, parentNode, size);
	}
}

int* MaxHeapSort(int* array, int size) {
	int* output = array;
	BuildMaxHeap(array, size);
	int root = 1;
	for (int i = size - 1 ; i > 0; i--) {
		arraySwap(array, i, root);
		output[i] = array[i];
		MaxHeapfy(array, 1, i);
	}
	return output;
}



int main() {
	int size = 15;
	// 9 8 7 6 4 3 
	// 내려갈 때 n*2, n*2+1
	// 올라갈 때 n/2
	int* array = MakeRandomArray(size);
	//int size = 7;
	//int* array = new int[size] {0, 7, 9, 4, 8, 6, 3};
	int* output = MaxHeapSort(array, size);
	for (int i = 1; i < size; i++) {
		cout << array[i] << ", ";
	} cout << endl;
	if (SortCheck(array, size) == true) {
		cout << "정렬검사결과 true" << endl;
	}
	else {
		cout << "정렬검사결과 false" << endl;
	}
}








