#include <iostream>

void delete_duplicates(int n, int a[10000]) {
	int i = 0;
	int j;
	int k;
	while (i < n) {
		j = 0;
		k = 0;
		while (j < i) {
			if (a[i] != a[j]) k++;
			j++;
		}
		if (k == i) std::cout << a[i] << " ";
		i++;
	}
}

int main() {
	int n;
	std::cin >> n;
	int a[10000];
	int i = 0;
	while (i < n) {
		std::cin >> a[i];
		i++;
	}
	delete_duplicates(n, a);
	return 0;
}