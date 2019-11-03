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

void delete_annoying_primes(int d, int arr[257814]) {
	int i = 0;
	int j;
	int k;
	while (i < d) {
		if (!if_prime(arr[i]) or arr[i] == 0) {
			std::cout << arr[i] << " ";
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

			std::cout << arr[i] << " ";
		}
		i++;
	}
}

int main() {
	int f = 0;
	std::cin >> f;
	int a[257814];
	int i = 0;
	while (i < f) {
		std::cin >> a[i];
		i++;
	}
	delete_annoying_primes(f, a);
	return 0;
}