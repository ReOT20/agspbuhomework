#include <iostream>
#include <cmath>

int main() {
	long n;
	std::cin >> n;
	long i = 0;
	int* arr = new int[n*2];
	while (i < n*2) {
		arr[i] = 1;
		i++;
	}
	i = 1;
	while (i <= long(sqrt(n*2))+1) {
		long j = i + i + 2;
		while (j < n*2 + 2) {
			arr[j - 1] = 0;
			j += i + 1;
		}
		i += 1;
	}
	i = 3;
	long j = 0;
	while (i < n*2 && j < n) {
		if (arr[i] == 0) {
			std::cout << i + 1 << " ";
			j++;
		}
		i++;
	}
	return 0;
}

/*Напишите программу находящую первые n составных чисел.*/