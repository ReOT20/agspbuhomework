#include <iostream>

int* cut(int* Array, int a, int b) {
	int i = a;
	int* arr = new int[b - a];
	while (i < b) {
		arr[i - a] = Array[i];
		i++;
	}
	return arr;
}

int strange_sum(int* arr, int n) {
	if (n == 1) return arr[0];
	return strange_sum(cut(arr, 0, n - n / 2), n - n / 2) + strange_sum(cut(arr, n - n / 2, n), n / 2);
}

int main() {
	int n;
	std::cin >> n;
	int* Array = new int[n + 1];
	int i = 0;
	while (i < n) {
		std::cin >> Array[i];
		i++;
	}
	std::cout << strange_sum(Array, n);
	return 0;
}