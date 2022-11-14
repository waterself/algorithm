#include <iostream>
#include "MergeSort.h"
using namespace std;
int cnt = 0;
void MergeSort(int* array, int left, int right){
    int middle = (left + right) / 2;
    if (left < right) {
        MergeSort(array, left, middle);
        for (int i = left; i <= middle; i++) {
            for (int j = middle + 1; j < right; j++) {
                if (array[i] > array[j]) {
                    arraySwap(array, i, j);
                }
            }
        }
        MergeSort(array, middle + 1, right);
        for (int i = left; i <= middle; i++) {
            for (int j = middle + 1; j < right; j++) {
                if (array[i] > array[j]) {
                    arraySwap(array, i, j);
                }
            }
        }
    }
}

int main(){
    int size = 10;
    int* array = new int[10]{5,2,7,4,8,9,1,0,3,6};
    MergeSort(array, 0, size);
    arrayPrint(array, size);
    delete[] array;
}