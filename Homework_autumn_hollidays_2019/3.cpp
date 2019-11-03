#include <iostream>

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

void build_ziggurat(int n) {
	int i = 0;
	int j;
	while (i < n - n / 2) {
		j = 0;
		int k = 1;
		while (j < n) {
			std::cout << k << " ";
			if (j < max(n / 2, n - n / 2) && k < i + 1) {
				k++;
			}
			else if ((j >= max(n / 2, n - n / 2) && k >= n - j) || (k == n - n / 2 && n % 2 == 1)) {
				k--;
			}
			j++;
		}
		std::cout << "\n";
		i++;
	}
	i = n / 2 - 1;
	while (i >= 0) {
		j = 0;
		int k = 1;
		while (j < n) {
			std::cout << k << " ";
			if (j < max(n / 2, n - n / 2) && k < i + 1) {
				k++;
			}
			else if ((j >= max(n / 2, n - n / 2) && k >= n - j) || (k == n - n / 2 && n % 2 == 1)) {
				k--;
			}
			j++;
		}
		std::cout << "\n";
		i--;
	}

}

int main() {
	int n;
	std::cin >> n;
	build_ziggurat(n);
	return 0;
}