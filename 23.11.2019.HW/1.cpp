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
		std::cout << x * 2020 + y * 2021 << "\n";
	}
	return 0;
}

/*Напишите программу, находящую натуральные корни уравнения
2020X + 2021Y=78487894 эффективным перебором.*/

/*Перебор эффективный т.к. сначала мы находим первую пару корней по значению Y,
у которого коэфицент больше чем у X, а значит и возможных значений меньше.
При этом переборе мы используем в шаг 10 и последняя цифра у Y 4 т.к. 
это единственный способ при данных значениях коэфициэнта у X и Y получить 4 на конце 78487894.
Максимальное значение Y берём 78487894/2021 углённое вниз к последней цифре 4.
После этого мы запускаем цикл в 19 итераций просто изменяя X и Y на фиксированный коэфицент.*/