#include <iostream>
#include <vector>
using namespace std;

vector<int> selectSort(vector<int> in, int size) {
	vector<int> v = in;
	int temp;
	int index = 0;
	for (int i = 0; i < size; i++) {
		int min = v.at(i);
		for (int j = i; j < size; j++) {
			int element = v.at(j);
			if (element <= min) {
				min = element;
				index = j;
			}
		}
		temp = v[i];
		v[i] = min;
		v[index] = temp;
	}
	return v;
}

int main() {
	// 0 1 2 3 3 4 6 7 8 9
	// vector<int> v = { 3,2,6,8,4,3,9,0,1,7 };
	vector<int> v = { 6, 2, 8, 4 };
	int size = v.size();
	vector<int> res = selectSort(v, size);
	for (int i = 0; i < size; i++) {
		cout << "index " << i << " : " << res.at(i) << endl;
	}
}