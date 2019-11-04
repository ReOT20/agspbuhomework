#include <iostream>

int abs(int x) {
	if (x < 0) return (x * -1);
	return x;
}

int** dig_trench(int** array, int n) {
	int i = 0;
	int j;
	int k;
	while (i < n) {
		j = 0;
		k = i * -1;
		while (j < n) {
			array[i][j] = abs(k);
			k++;
			j++;
		}
		i++;
	}
	return array;
}

int main() {
	int n;
	std::cin >> n;
	int** Trench = new int* [n];
	int i = 0;
	while (i < n) {
		Trench[i] = new int[n];
		i++;
	}
	Trench = dig_trench(Trench, n);
	int j;
	i = 0;
	while (i < n) {
		j = 0;
		while (j < n) {
			std::cout << Trench[i][j] << " ";
			j++;
		}
		std::cout << "\n";
		i++;
	}
	return 0;
}