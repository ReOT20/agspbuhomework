#include <iostream>

bool if_prime(int t) {
	int i = 2;
	int k = 0;
	while (i < t) {
		if (t % i == 0) k++;
		i++;
	}
	if (k == 0) return true;
	return false;
}

int* delete_annoying_primes(int d, int* arr) {
	int i = 0;
	int j;
	int k;
	int count = 1;
	int* array = new int[d + 1];
	while (i < d) {
		if (!if_prime(arr[i]) or arr[i] == 0) {
			array[count] = arr[i];
			count++;
			i++;
			continue;
		}
		j = 0;
		k = 0;
		while (j < d) {
			if (arr[i] != arr[j]) k++;
			if (i == j) k++;
			j++;
		}
		if (k == d) {
			array[count] = arr[i];
			count++;
		}
		i++;
	}
	array[0] = count;
	return array;
}

int main() {
	int n = 0;
	std::cin >> n;
	int* Array = new int[n + 1];
	int i = 0;
	while (i < n) {
		std::cin >> Array[i];
		i++;
	}
	Array = delete_annoying_primes(n, Array);
	i = 1;
	while (i < Array[0]) {
		std::cout << Array[i] << " ";
		i++;
	}
	return 0;
}