#include <iostream>
#include "insertSort.h"
using namespace std;
static int cnt;

int* insertSwap(int* input, int size) {
	int* output = input;
	for (int i = 1; i < size; i++) {
		int j = i;
		while (true) {
			if (output[j] >= output[j - 1]) {
				break;
			}
			else {
				arraySwap(output, j, j - 1);
				cnt++;
				j--;
			}
		}
	}
	return output;
}

int main() {
	int size = 1000;
	//int size = 5000;
	//int size = 10000;
	int* input = MakeRandomArray(size);
	double startTime, endTime;
	startTime = clock();
	int* output = insertSwap(input, size);
	endTime = clock();
	cout << "데이터" << size << "에 대한 실행시간은 " << endTime - startTime << "밀리초 입니다." << endl;
	cout << "교환횟수는" << cnt << "회" << endl;
	if (SortCheck(input, size)) {
		cout << "정렬검사결과 true" << endl;
	}
	else {
		cout << "정렬검사결과 false" << endl;
	}
	delete[] output;
	delete[] input;
	return 0;
}