#include <iostream>

using namespace std;

void MergeSort(int* array, int first, int last){
    if(last - first  > 1){
        int middle = last / 2;
        MergeSort(array, first, middle);
        MergeSort(array, middle+1, last);
    }
    if(last - first == 1){
        if(array[0] > array[1]){
            arraySwap(array, 0, 1);
        }
    }
}

int main(){
    int size = 10;
    int* array = new int[10]{5,2,7,4,8,9,1,0,3,6};
    MergeSort(array, 0, size);

}
