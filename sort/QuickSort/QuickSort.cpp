#include <iostream>
#include <time.h>
#include "QuickSort.h"
using namespace std;
static int cnt = 0;

void QuickSort(int* array, int left, int right) {
    int forward = 0, backward = 0, pivot = 0, pindex = 0;
    if (left < right) {
        pivot = array[right];
        pindex = right;
        forward = left - 1;
        backward = right;
        while (true) {
            while (array[++forward] < pivot);
            while (array[--backward] > pivot);
            if (forward >= backward)break;
            arraySwap(array, forward, backward);
            cnt++;
        //    cout << ++cnt << " 번째 변경: [";
        //    for (int i = 0; i < right - left + 1; i++) {
        //        cout << array[i] << ", ";
        //    }
        //    cout << "]" << endl;
        }
        arraySwap(array, forward, pindex);
        cnt++;
        //cout << ++cnt << " 번째 변경: [";
        //for (int i = 0; i < right - left + 1; i++) {
        //    cout << array[i] << ", ";
        //}
        /*cout << ']' << endl;*/
        QuickSort(array, left, forward - 1);
        //cout << ++cnt << " 번째 변경: [";
        //for (int i = 0; i < right - left + 1; i++) {
        //    cout << array[i] << ", ";
        //}
        /*cout << ']' << endl;*/
        QuickSort(array, forward + 1, right);
        //cout << ++cnt << " 번째 변경: [";
        //for (int i = 0; i < right - left + 1; i++) {
        //    cout << array[i] << ", ";
        //}
        //cout << ']' << endl;
    }
}

int main() {
    //int size = 8;
    //int* array = new int[size] {5, 1, 4, 2, 6, 8, 3, 9};
    //int size = 1000;
    //int size = 5000;
    int size = 10000;
    int* array = MakeRandomArray(size);
    double startTime, endTime;
    startTime = clock();
    QuickSort(array, 0, size - 1);
    endTime = clock();
    cout << "데이터" << size << "에 대한 실행시간은 " << endTime - startTime << "밀리초 입니다." << endl;
    //결과로 출력
    //for(int i = 0; i < size; i++){
    //    if (i % 10 == 0 && i != 0) {
    //        cout << array[i] << endl;
    //    }
    //    else {
    //        cout << array[i] << ", ";
    //    }
    //}
    cout << endl;
    //교환횟수
    cout << "교환횟수는" << cnt << "회" << endl;
    
    //정렬검사
    if (SortCheck(array, size)) {
        cout << "정렬검사결과 true" << endl;
    }
    else {
        cout << "정렬검사결과 false" << endl;
    }
}