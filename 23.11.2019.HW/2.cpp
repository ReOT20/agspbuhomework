#include <iostream>
#include <cmath>


long reverse(long n, long len) {
	long lim = pow(10, len - 1);
	long i = 0;
	long res = 0;
	while (i < len) {
		res += n % 10 * lim;
		n /= 10;
		lim /= 10;
		i += 1;
	}
	return res;
}


int main() {
	long n;
	std::cin >> n;
	long i = pow(10, n - n / 2 - 1);
	long len = n - n / 2;
	long j;
	int check;
	while (i < pow(10, n - n / 2)) {
		j = 0;
		while (j < n - n / 2 - len) {
			std::cout << 0;
			j++;
		}
		if (i != 0 and n != 1) {
			if (n % 2 == 1) std::cout << i / 10;
			else std::cout << i;
		}
		if (i % 10 == 0) std::cout << 0;
		if (i % 100 == 0) std::cout << 0;
		std::cout << reverse(i, len);
		j = 0;
		while (j < n - n / 2 - len) {
			std::cout << 0;
			j++;
		}
		std::cout << "\n";
		i++;
	}
	return 0;
}