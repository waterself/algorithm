#include <iostream>
#include "HeapSort.h"
using namespace std;

void MaxHeapfy(int* array, int first, int size) {
	int currenNode = first;

	int leftChild = currenNode * 2 + 1;
	int rightChild = currenNode * 2 + 2;

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
	cout << "Build Max heap" << endl;
	for (int i = 0; i < size; i++) cout << "index[" << i << "] : " << array[i] << ", ";
	cout << endl;
}

int* MaxHeapSort(int* array, int size) {
	int* output = array;
	BuildMaxHeap(array, size);
	int root = 0;
	for (int i = size - 1 ; i > 0; i--) {
		arraySwap(array, i, root);
		output[i] = array[i];
		cout << "swap last, root" << endl;
		for (int i = 0; i < size; i++) cout << "index[" << i << "] : " << output[i] << ", ";
		cout << endl;
		MaxHeapfy(array, 0, i);
		cout << "heapfy" << endl;
		for (int i = 0; i < size; i++) cout << "index[" << i << "] : " << array[i] << ", ";
		cout << endl;
	}
	return output;
}



int main() {
	//int size = 100;
	// ������ �� n*2, n*2+1
	// �ö� �� n/2
	//int* array = MakeRandomArray(size);
	int size = 6;
	//3, 4, 6, 7, 8, 9
	int* array = new int[size] {3, 6, 4, 8, 9, 7};
	int* output = MaxHeapSort(array, size);
	cout << "Heap Sort Done" << endl;
	for (int i = 0; i < size; i++) cout << "index[" << i << "] : " << array[i] << ", ";
	cout << endl;
	delete[] array;
	delete[] output;
	return 0;
}








