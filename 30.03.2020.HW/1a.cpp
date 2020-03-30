#include <iostream>
#include <string>
using namespace std;


int main() {
	string a, b;
	cin >> a >> b;
	int c = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i]) c++;
	}
	cout << c;
	return 0;
}