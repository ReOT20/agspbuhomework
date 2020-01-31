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

	Array& operator= (const Array& b) {
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


struct Vector {
	int size = 0;
	int* data;
	int capacity = 0;

	Vector() {}

	Vector(int x) {
		size = x;
		capacity = size * 2;
		data = new int[capacity];
	}

	Vector(const Vector& A) {
		size = A.size;
		capacity = A.capacity;
		data = new int[capacity];
		for (int i = 0; i < size; i++) {
			data[i] = A.data[i];
		}
	}

	~Vector() {
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

	int& Capacity() {
		return capacity;
	}

	Vector& operator= (const Vector& b) {
		if (capacity != b.capacity) {
			if (capacity != 0) {
				delete[] data;
				int* data;
			}
			size = b.size;
			capacity = b.capacity;
			data = new int[capacity];
		}
		for (int i = 0; i < size; i++) {
			data[i] = b.data[i];
		}
		return *this;
	}

	void push_back(int x) {
		if (size == capacity) {
			if (capacity == 0) {
				capacity = 1;
			}
			capacity *= 2;
			int* temp = new int[capacity];
			for (int i = 0; i < size; i++) {
				temp[i] = data[i];
			}
			if (size != 0)
				delete[] data;
			data = temp;
		}
		data[size] = x;
		size++;
	}
};


int main() {
	return 0;
}