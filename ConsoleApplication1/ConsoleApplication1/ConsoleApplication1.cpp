#include <iostream>
#include <string>
using namespace std;


int main() {
	cout << "Enter 2 words\n";
	string a, b;
	cin >> b >> a;
	b = ' ' + b;
	a = ' ' + a;
	int dc, inc, rc;
	cout << "Enter delete cost\n";
	cin >> dc;
	cout << "Enter insert cost\n";
	cin >> inc;
	cout << "Enter replace cost\n";
	cin >> rc;
	int d1, d2, d3;
	int** arr = new int* [a.length()];
	for (int i = 0; i < a.length(); i++) {
		arr[i] = new int[b.length()];
		for (int j = 0; j < b.length(); j++) {
			if (i == 0 and j == 0) {
				arr[i][j] = 0;
			}
			else if (j == 0 and i > 0) {
				arr[i][j] = i * dc;
			}
			else if (i == 0 and j > 0) {
				arr[i][j] = j * dc;
			}
			else if (a[i] == b[j]) {
				arr[i][j] = arr[i - 1][j - 1];
			}
			else {
				d1 = arr[i][j - 1] + inc;
				d2 = arr[i - 1][j] + dc;
				d3 = arr[i - 1][j - 1] + rc;
				if (d1 < d2 and d1 < d3) {
					arr[i][j] = d1;
				}
				else if (d2 < d1 and d2 < d3) {
					arr[i][j] = d2;
				}
				else {
					arr[i][j] = d3;
				}
			}
		}
	}
	cout << arr[a.length() - 1][b.length() - 1];
}