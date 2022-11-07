//BinarySearch.cpp
#include <iostream>
using namespace std;

int BinarySearch(int array[], int left, int right, int searchKey) {
    int l = left; int r = right; int mid = 0; int cnt = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        cout << "loop: " << ++cnt << "\tl: " << l << "\tr: " << r << "\tmid: " << mid << endl;
        if (array[mid] == searchKey) return mid;
        if (array[mid] > searchKey) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main() {
    int searchKey = 67;
    int size = 10;
    int* array = new int[size] {1, 7, 11, 12, 14, 23, 67, 139, 672, 871};
    int searchIndex = BinarySearch(array, 0, size - 1, searchKey);
    cout << "index: " << searchIndex << endl;
    cout << "value: " << array[searchIndex] << endl;
    delete[] array;
    return 0;
}