#include <iostream>

int* delete_duplicates(int n, int* a) {

	int i = 0;
	int j;
	int k;
	int* Array = new int[n + 1];
	int count = 1;
	while (i < n) {
		j = 0;
		k = 0;
		while (j < i) {
			if (a[i] != a[j]) k++;
			j++;
		}
		if (k == i) {
			Array[count] = a[i];
			count++;
		}
		i++;
	}
	Array[0] = count;
	return Array;
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
	Array = delete_duplicates(n, Array);
	i = 1;
	while (i < Array[0]) {
		std::cout << Array[i] << " ";
		i++;
	}
	return 0;
}