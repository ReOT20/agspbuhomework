#include <iostream>
#include <string>
using namespace std;


int min(int a, int b, int c) {
	if (a < b and a < c) return a;
	if (b < c) return b;
	return c;
}


int main() {
	cout << "Enter 2 words\n";
	string a, b;
	cin >> b >> a;
	b = '´' + b;
	a = '´' + a;
	int dc, inc, rc;
	cout << "Enter delete cost\n";
	cin >> dc;
	cout << "Enter insert cost\n";
	cin >> inc;
	cout << "Enter replace cost\n";
	cin >> rc;
	int** arr = new int* [a.length()];
	for (int i = 0; i < a.length(); i++) {
		arr[i] = new int[b.length()];
	}
	arr[0][0] = 0;
	for (int j = 1; j < b.length(); j++) {
		arr[0][j] = arr[0][j - 1] + inc;
	}
	for (int i = 1; i < a.length(); i++) {
		arr[i][0] = arr[i - 1][0] + dc;
		for (int j = 1; j < b.length(); j++) {
			if (a[i] != b[j]) {
				arr[i][j] = min(arr[i - 1][j] + dc, arr[i][j - 1] + inc, arr[i - 1][j - 1] + rc);
			}
			else {
				arr[i][j] = arr[i - 1][j - 1];
			}
		}
	}
	cout << arr[a.length() - 1][b.length() - 1];
}