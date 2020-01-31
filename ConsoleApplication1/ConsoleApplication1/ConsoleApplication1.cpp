#include <iostream>
using namespace std;


struct Array {
	int size = 0;
	int* data;
	
	Array() {}

	Array(int x) {
		size = x;
		data = new int[size];
	}

	Array(const Array& A) {
		if (size != A.size && data != A.data) {
			size = A.size;
			data = new int[size];
			for (int i = 0; i < size; i++) {
				data[i] = A.data[i];
			}
		}
	}

	~Array() {
		delete[] data;
	}

	int& operator[] (int i) {
		if (i < 0 || i >= size) {
			std::cout << "Err";
			return data[0];
		}
		return data[i];
	}

	int& Size() {
		return size;
	}

	Array& operator= (Array& b) {
		if (size != b.size) {
			if (size != 0) {
				delete[] data;
				int* data;
			}
			size = b.size;
			data = new int[size];
		}
		for (int i = 0; i < size; i++) {
			data[i] = b.data[i];
		}
		return *this;
	}
};


int main() {
	Array a(1);
	a[0] = 2;
	Array b(4);
	b = a;
	cout << (a[0] == b[0] && a.Size() == b.Size());
	return 0;
}