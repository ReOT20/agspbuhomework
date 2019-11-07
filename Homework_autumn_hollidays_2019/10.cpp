#include <iostream>
#include <cstdlib>
#include <cmath>

unsigned long int sum(unsigned long int* arr) {
	unsigned long int i = 2;
	unsigned long int s = 0;
	while (i < 10) {
		s += arr[i] * arr[i] * arr[i];
		i++;
	}
	return s;
}

unsigned long int crt(unsigned long int n) {
	unsigned long i = long(pow(n, (1.0 / 3)));
	if ((i + 1) * (i + 1) * (i + 1) <= n) return i + 1;
	return i;
}

unsigned long int cub(unsigned long int* arr) {
	if (arr[1] > 10) {
		if (sum(arr) == arr[12]) {
			unsigned long int i = 2;
			unsigned long int s = 0;
			while (s != arr[12] && i < 10) {
				s += arr[i] * arr[i] * arr[i];
				std::cout << arr[i] << " ";
				i++;
			}
			if (arr[12] == 0) std::cout << 0;
			exit(0);
		}
	}
	else {
		unsigned long int n = crt(arr[0]);
		unsigned long int* Array = new unsigned long int[12];
		while (n >= 0) {
			if (arr[1] > 10) return 0;
			Array = arr;
			Array[arr[1]] = n;
			Array[0] -= n * n * n;
			Array[1]++;
			cub(Array);
			n--;
		}

	}
	return 0;
}

int main() {
	unsigned long int n;
	std::cin >> n;
	unsigned long int* arr = new unsigned long int[12];
	arr[0] = n;
	arr[1] = 2;
	arr[12] = n;
	unsigned long int i = 2;
	while (i < 12) {
		arr[i] = -1;
		i++;
	}
	cub(arr);
	std::cout << "Impossible";
	return 0;
}
