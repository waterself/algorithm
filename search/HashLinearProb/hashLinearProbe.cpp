#include <iostream>
using namespace std;


int HashFunction(int key, int mod) {
	return key % mod;
}

int* HashLinearProbe(int* array, int keySize, int mod) {
	int k = keySize; 
	int* key = array;
	int* hash = new int[keySize];
	int* hashTable = new int[mod];
	//initialize hash array
	for (int i = 0; i < mod; i++) {
		hashTable[i] = -1;
	}
	//get hash
	for (int i = 0; i < keySize; i++) {
		hash[i] = HashFunction(key[i], mod);
	}
	//i는 해시테이블에 순차접근하는 인덱스
	int hashIndex = 0;
	int hashTemp;
	for (int i = 0; i < keySize; i++) {
		if (hashTable[hash[hashIndex]] == -1) {
			hashTable[hash[hashIndex]] = key[hashIndex];
		}
		else {
			hashTemp = hash[hashIndex] + 1;
			while (hashTable[hashTemp] != -1) {
				hashTemp++;
			}
			hashTable[hashTemp] = key[i];
		}
		if(hashIndex < keySize - 1)hashIndex++;
		cout << key[i] << "의 배치: ";
		for (int i = 0; i < mod; i++) cout << hashTable[i] << ",\t";
		cout << endl;
	}
	return hashTable;
}

int main() {
	int size = 17;
	int mod = 19;
	int* array = new int[size] { 1, 19, 5, 1, 18, 3, 8, 9, 14, 7, 5, 24, 1, 13, 16, 12, 5 };
	int* output = HashLinearProbe(array, size, mod);
	cout << "done table: ";
	for (int i = 0; i < mod; i++) cout << output[i] << ",\t";
	cout << endl;
}