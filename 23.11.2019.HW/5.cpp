/*Напишите программу, находящую все простые числа Ченя не превосходящие n.*/

#include <iostream>
#include <cmath>

long* chen(long n) {
	long i = 0;
	long* arr = new long[n];
	while (i < n) {
		arr[i] = 0;
		i++;
	}
	i = 1;
	while (i <= long(sqrt(n)) + 1) {
		long j = i + i + 2;
		while (j < n + 2) {
			arr[j - 1] = i + 1;
			j += i + 1;
		}
		i += 1;
	}
	i = 1;
	long j = 1;
	long* ans = new long[n];
	while (i < n - 2) {
		if ((arr[i + 2] == 0 || (arr[arr[i + 2] - 1] == 0 && arr[i / (arr[i + 2] - 1)] == 0)) && arr[i] == 0) {
			ans[j] = i + 1;
			j += 1;
		}
		i++;
	}
	ans[0] = j;
	return ans;
}


int main() {
	long n;
	std::cin >> n;
	n += 2;
	long* arr = new long[n];
	arr = chen(n);
	long i = 1;
	while (i < arr[0]) {
		std::cout << arr[i] << " ";
		i++;
	}
	return 0;
}