/*�������� ������� ��������� ������ ���������� ������������ �������
f �������� �������(���������). ����� ������� ��� ������ ����������� ����������.
������ ����� ������� �������� x, ����� ��� |f(x)|<10^(-6).*/

/*�������� ���������� �.�. �� ������ ������������ �� ����������� ����� O(100000).
��� ������� ����������� ����� ��������� �������� �� ����� ������ �����������,
�.�. ��� ������ �������� �������� ������ ����������� � 2 ���� � ���� ���
���������� ��������� ��� ���� double �� ���������� ������� ������ ����� 64 ��������.
���� ������ ������, �� ��������� ����������� ��������������.*/

/*�������� ������ �������� � ����������. ������� ������� ������ ������� f(x)*/


#include <iostream>
#include <cmath>

double f(double x) {
	return x + 3;
}

int main() {
	double l, r;
	std::cin >> l >> r;
	int i = 0;
	while (i < 100000) {
		if (f((l + r) / 2) > 0) r = (l + r) / 2;
		else if (f((l + r) / 2) < 0) l = (l + r) / 2;
		else break;
		i++;
	}
	std::cout << (l + r) / 2;
	return 0;
}