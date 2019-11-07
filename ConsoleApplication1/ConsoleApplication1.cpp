#include <iostream>
#include <cstdlib>

int sum(int* arr) {
	int i = 2;
	int s = 0;
	while (arr[i] != 0) {
		s += arr[i]* arr[i]* arr[i];
		i++;
	}
	return s;
}

int* cut(int* Array, int a, int b) {
	int i = a;
	int* arr = new int[b - a];
	while (i < b) {
		arr[i - a] = Array[i];
		i++;
	}
	return arr;
}

int crt(int n) {
	int i = n;
	while (i * i * i > n) i--;
	return i;
}

int cub(int* arr) {
	if (arr[1] == 11) {
		if (arr[10] == 0) {
			int i = 2;
			while (arr[i] != 0) {
				std::cout << arr[i] << " ";
				i++;
			}
			std::cout << "\n" << sum(arr);
			//std::cin >> i;
			exit(0);
		}
		return 0;
	}
	int n = crt(arr[0]);
	int* Array = new int[11];
	while (n >= 0) {
		Array = arr;
		Array[arr[1]] = n;
		Array[0] -= n * n * n;
		Array[1]++;
		cub(Array);
		n--;
	}
	return 0;
}

int main() {
	int n;
	std::cin >> n;
	int* arr = new int[11];
	arr[0] = n;
	arr[1] = 2;
	int i = 2;
	while (i < 12) {
		arr[i] = -1;
		i++;
	}
	cub(arr);
	std::cout << "Impossible";
	return 0;
}
