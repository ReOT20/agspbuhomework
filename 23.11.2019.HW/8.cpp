/*Напишите функцию вычисляющую праймориал числа.*/

#include <iostream>
#include <cmath>

long prime(long n) {
	long i = 0;
	int* arr = new int[n];
	while (i < n) {
		arr[i] = 1;
		i++;
	}
	i = 1;
	while (i <= long(sqrt(n)) + 1) {
		long j = i + i + 2;
		while (j < n + 2) {
			arr[j - 1] = 0;
			j += i + 1;
		}
		i += 1;
	}
	i = 0;
	long sum = 1;
	while (i < n) {
		if (arr[i] == 1) {
			sum *= (i + 1);
		}
		i++;
	}
	return sum;
}


int main() {
	long n;
	std::cin >> n;
	std::cout << prime(n);
	return 0;
}