#include <iostream>


int binsearch(int*& arr, int num, int a, int b) {
	int res;
	if (b - a == 1) return a;
	if (num < arr[(a + b) / 2]) {
		res = binsearch(arr, num, a, (a + b) / 2);
	}
	else {
		res = binsearch(arr, num, (a + b) / 2, b);
	}
	return res;
}


int main() {
	int n;
	std::cin >> n;
	int* arr = new int[n];
	int i = 0;
	while (i < n) {
		std::cin >> arr[i];
		i++;
	}
	int a, b;
	std::cin >> a >> b;
	int cursor = binsearch(arr, a, 0, n);
	std::cout << cursor;
	return 0;
}