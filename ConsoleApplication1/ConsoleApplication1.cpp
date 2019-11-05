#include <iostream>

int strange_multiply(int n, int m) {
	int res = 0;
	while (m) {
		if (m & 1)
			res += n;
		n += n;
		m >>= 1;
	}
	return res;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::cout << strange_multiply(n, m);
	return 0;
}
