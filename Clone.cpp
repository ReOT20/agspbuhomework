#include <iostream>
using namespace std;


struct Array {
	int size;
	int* data;
	Array(int x) {
		size = x;
		data = new int[size];
	}
	Array(const Array& A) {
		size = A.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = A.data[i];
		}
	}
	~Array() {
		delete[] data;
	}
};
