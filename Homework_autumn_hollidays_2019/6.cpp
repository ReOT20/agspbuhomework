#include <iostream>

int** put_snake(int** Snake, int n, int m) {
	int curX = m - 1;
	int curY = 0;
	int direction = 2;
	int top_border = 0;
	int left_border = 0;
	int bottom_border = n - 1;
	int right_border = m - 1;
	int i = n * m - 1;
	Snake[curY][curX] = i;
	while (i > 0) {
		if (direction == 2) {
			curX--;
			if (curX == left_border) {
				direction = 3;
				top_border++;
			}
		}
		else if (direction == 3) {
			curY++;
			if (curY == bottom_border) {
				direction = 4;
				left_border++;
			}
		}
		else if (direction == 4) {
			curX++;
			if (curX == right_border) {
				direction = 1;
				bottom_border--;
			}
		}
		else {
			curY--;
			if (curY == top_border) {
				direction = 2;
				right_border--;
			}
		}
		i--;
		Snake[curY][curX] = i;
	}
	return Snake;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	int** Snake = new int* [n];
	int i = 0;
	while (i < n) {
		Snake[i] = new int[m];
		i++;
	}
	Snake = put_snake(Snake, n, m);
	int j;
	i = 0;
	while (i < n) {
		j = 0;
		while (j < m) {
			std::cout << Snake[i][j] << "\t";
			j++;
		}
		std::cout << "\n";
		i++;
	}
	return 0;
}