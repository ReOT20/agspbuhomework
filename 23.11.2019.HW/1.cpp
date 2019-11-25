#include <iostream>
 
int main() {
	int y = 38834;
	bool check = true;
	int x;
	while (check) {
		if (((78487894 - 2021 * y) % 2020) == 0) {
			x = (78487894 - 2021 * y) / 2020;
			check = false;
		}
		y -= 10;
	}
	y += 10;
	while (y > 0) {
		std::cout << x << "\t" << y << "\n";
		y -= 2020;
		x += 2021;
	}
	return 0;
}

/*�������� ���������, ��������� ����������� ����� ���������
2020X + 2021Y = 78487894 ����������� ���������.*/