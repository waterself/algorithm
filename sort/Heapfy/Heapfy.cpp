#include <iostream>
using namespace std;

void Heapfy(int* array, int size) {
    for (int i = size / 2 ; i >= 1; i--) {
        int parent = array[i];
        int j;
        for (j = i * 2; j <= size; j = j * 2) {
            if (array[j] < array[j + 1]) {
                j++;
            }
            if (parent >= array[j]) {
                break;
            }
            else {
                //j / 2는 그 부모 노드를 뜻한다.
                array[j / 2] = array[j];
                cout << "in " << j << " loop" << endl;
                for (int i = 1; i < size; i++) cout << array[i] << ", ";
                cout << endl;
                
            }
        }
        array[j / 2] = parent;
        cout << "out of j loop" << endl;
        for (int i = 1; i < size; i++) cout << array[i] << ", ";
        cout << endl;
    }
}

int main() {
    int size = 11;
    
    int* array = new int[size] {0, 6, 2, 8, 1, 3, 9, 4, 5, 10, 7};
    Heapfy(array, size);
    for (int i = 1; i < size; i++) cout << array[i] << ", ";
    cout << endl;
    return 0;
}