#include <iostream>

int abs(int x) {
	if (x < 0) return (x * -1);
	return x;
}

int proper_fraction(int n) {
	int res = n;
	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			res -= res/i;
		}
		i++;
	}
	if (n > 1) return (res - res/n)*2;
	return res*2;
}

int main() {
	int n;
	std::cin >> n;
	std::cout << proper_fraction(abs(n));
	return 0;
}