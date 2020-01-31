#include <iostream>

int merg(int*& arr, int a, int b) {
	if (b - a > 1) {
		merg(arr, a, (a + b) / 2);
		merg(arr, (a + b) / 2, b);
	}
	else return 0;
	int* res = new int[b - a];
	int i = 0;
	int j = 0;
	while (i + j < b - a) {
		if ((i + a) < ((a + b) / 2) && (j + ((a + b) / 2)) < b) {
			if (arr[i + a] > arr[j + (a + b) / 2]) {
				res[i + j] = arr[j + (a + b) / 2];
				j++;
			}
			else {
				res[i + j] = arr[i + a];
				i++;
			}
		}
		else if (i + a < (a + b) / 2) {
			res[i + j] = arr[i + a];
			i++;
		}
		else {
			res[i + j] = arr[j + (a + b) / 2];
			j++;
		}
	}
	i = a;
	while (i < b) {
		arr[i] = res[i - a];
		i++;
	}
	return 0;
}


int main() {
	int n;
	std::cin >> n;
	int i = 0;
	int* arr = new int[n];
	while (i < n) {
		std::cin >> arr[i];
		i++;
	}
	merg(arr, 0, n);
	i = 0;
	while (i < n) {
		std::cout << arr[i] << ' ';
		i++;
	}
	return 0;
}