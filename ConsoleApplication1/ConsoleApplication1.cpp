#include <iostream>
#include <cstdlib>

int sum(int* arr) {
	int i = 2;
	int s = 0;
	while (i < 10) {
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
		//std::cout << arr[2] << " ";
		//std::cout << arr[3] << " ";
		//std::cout << arr[4] << " ";
		//std::cout << arr[5] << " ";
		//std::cout << arr[6] << " ";
		//std::cout << arr[7] << " ";
		//std::cout << arr[8] << " ";
		//std::cout << arr[9] << " ";
		//std::cout << arr[10] << " ";
		//std::cout << sum(arr) << " ";
		//std::cout << arr[12] << " ";
		if (sum(arr) == arr[12]) {
			int i = 2;
			int s = 0;
			while (s != arr[12]) {
				s += arr[i] * arr[i] * arr[i];
				std::cout << arr[i] << " ";
				i++;
			}
			if (arr[12] == 0) std::cout << 0;
			//std::cin >> i;
			exit(0);
		}
		return 0;
	}
	int n = crt(arr[0]);
	int* Array = new int[12];
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
	int* arr = new int[12];
	arr[0] = n;
	arr[1] = 2;
	arr[12] = n;
	int i = 2;
	while (i < 12) {
		arr[i] = -1;
		i++;
	}
	cub(arr);
	std::cout << "Impossible";
	return 0;
}
