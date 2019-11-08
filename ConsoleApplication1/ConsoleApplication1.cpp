#include <iostream>

int** build_ziggurat(int n, int** Ziggurat) {
	int i = 0;
	int j;
	int count = 0;
	while (i < n - n / 2) {
		j = 0;
		int k = 1;
		while (j < n) {
			Ziggurat[count][j] = k;
			if (j < (n - n / 2) && k < i + 1) k++;
			else if ((j >= (n - n / 2) && k >= n - j) || (k == n - n / 2 && n % 2 == 1)) k--;
			j++;
		}
		count++;
		i++;
	}
	i = n / 2 - 1;
	while (i >= 0) {
		j = 0;
		int k = 1;
		while (j < n) {
			Ziggurat[count][j] = k;
			if (j < (n - n / 2) && k < i + 1) {
				k++;
			}
			else if ((j >= (n - n / 2) && k >= n - j) || (k == n - n / 2 && n % 2 == 1)) {
				k--;
			}
			j++;
		}
		count++;
		i--;
	}
	return Ziggurat;
}

int main() {
	int n;
	std::cin >> n;
	int** Ziggurat = new int* [n];
	int i = 0;
	while (i < n) {
		Ziggurat[i] = new int[n];
		i++;
	}
	Ziggurat = build_ziggurat(n, Ziggurat);
	i = 0;
	int j;
	while (i < n) {
		j = 0;
		while (j < n) {
			std::cout << Ziggurat[i][j] << " ";
			j++;
		}
		std::cout << "\n";
		i++;
	}
	return 0;
}