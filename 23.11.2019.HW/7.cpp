#include <iostream>

bool ecual(char* arr, char* b, int l) {
	int i = 0;
	while (i < l) {
		if (arr[i] != b[i]) {
			return false;
		}
		i++;
	}
	return true;
}

int main() {
	int l;
	std::cin >> l;
	char* arr = new char[l];
	char buff;
	int i = 0;
	while (i < l) {
		std::cin >> arr[i];
		i++;
	}
	char* b = new char[l];
	b = arr;
	int check = 0;
	while (ecual(arr, b, l) == false || check == 0) {
		for (int i = l - 1; i > 0; i--) {
			if (b[i - 1] < b[i]) {
				int t = i;
				for (int j = t; j < l; j++) {
					if (int(b[j]) <= int(b[t]) && int(b[i - 1]) < int(b[j])) {
						t = j;
					}
				}
				buff = b[i - 1];
				b[i - 1] = b[t];
				b[t] = buff;

				for (int j = l - 1; i < j; i++, j--) {
					buff = b[i];
					b[i] = b[j];
					b[j] = buff;
				}
				break;
			}
		}
		check = 1;
		if (true) {
			i = 0;
			while (i < l) {
				std::cout << b[i] << ' ';
				i++;
			}
			std::cout << ' ' << ecual(arr, b, l) << '\n';

		}
	}
	return 0;
}