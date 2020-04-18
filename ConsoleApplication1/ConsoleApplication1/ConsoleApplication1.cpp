#include <iostream>
#include <string>
using namespace std;


int main() {
	bool* disk_1 = new bool[8];
	bool* disk_2 = new bool[8];
	bool* disk_3 = new bool[8];
	bool* disk_4 = new bool[8];
	cout << "Input disk 1 data:\n";
	for (int i = 0; i < 8; i++) {
		cin >> disk_1[i];
	}
	cout << "Input disk 2 data:\n";
	for (int i = 0; i < 8; i++) {
		cin >> disk_2[i];
	}
	cout << "Input disk 3 data:\n";
	for (int i = 0; i < 8; i++) {
		cin >> disk_3[i];
	}
	cout << "Generating controll sum...\n";
	for (int i = 0; i < 8; i++) {
		disk_4[i] = disk_1[i] ^ disk_2[i] ^ disk_3[i];
	}
	cout << "Loosing disk 2 data...\n";
	for (int i = 0; i < 8; i++) {
		disk_2[i] = 0;
	}
	cout << "Restoring disk 2 data...\n";
	for (int i = 0; i < 8; i++) {
		disk_2[i] = disk_1[i] ^ disk_3[i] ^ disk_4[i];
	}
	cout << "Completed!\n";
	cout << "Reading disk 2 data:\n";
	for (int i = 0; i < 8; i++) {
		cout << disk_2[i] << " ";
	}
	return 0;
}