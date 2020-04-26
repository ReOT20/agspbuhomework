#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool sortinrev(const pair<int, int>& a, const pair<int, int>& b) {
	return (a.first > b.first);
}


int generate() {
	cout << "Please type your string here:\n";
	string s;
	cin >> s;
	string copy = s;
	char letter;
	int count;
	vector<pair <int, char>> vect;
	while (copy.size() > 0) {
		letter = copy[0];
		count = 1;
		for (int i = 1; i < copy.size(); i++) {
			if (letter == copy[i]) {
				count++;
			}
		}
		copy.erase(remove(copy.begin(), copy.end(), letter), copy.end());
		vect.push_back(make_pair(count, letter));
	}
	sort(vect.begin(), vect.end(), sortinrev);
	int num = 0;
	for (int i = 0; i < vect.size() - 1; i++) {
		num *= 10;
		vect[i].first = num;
		num++;
	}
	vect[vect.size() - 1].first = num;
	cout << "Gotcha! Thats your code!\n";
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i].first << " " << vect[i].second << "\n";
	}
	return 0;
}


int code() {
	cout << "Please type text to code:\n";
	string text;
	cin >> text;
	cout << "Here type number of symbols in code:\n";
	int num;
	cin >> num;
	cout << "Now type your code here in format of pairs\nof char and int with space between and enter between pairs:\n";
	vector<pair <int, char>> vect;
	int cod;
	char symb;
	for (int i = 0; i < num; i++) {
		cin >> symb;
		cin >> cod;
		vect.push_back(make_pair(cod, symb));
	}
	sort(vect.begin(), vect.end());
	int j;
	cout << "Check it out!\n";
	for (int i = 0; i < text.length(); i++) {
		j = 0;
		while (text[i] != vect[j].second) {
			j++;
		}
		cout << vect[j].first;
	}
	return 0;
}


int decode() {
	cout << "Please type text to decode:\n";
	string text;
	cin >> text;
	cout << "Here type number of symbols in code:\n";
	int num;
	cin >> num;
	cout << "Now type your code here in format of pairs\nof char and int with space between and enter between pairs:\n";
	vector<pair <int, char>> vect;
	int cod;
	char symb;
	for (int i = 0; i < num; i++) {
		cin >> symb;
		cin >> cod;
		vect.push_back(make_pair(cod, symb));
	}
	sort(vect.begin(), vect.end());
	int now = 0;
	int max = to_string(vect[vect.size() - 1].first).length();
	cout << "How do you like it, Your Name?!\n";
	for (int i = 0; i < text.length(); i++) {
		if (text[i] != '0' and now != max) {
			now++;
			if (now == max) {
				cout << vect[now].second;
				now = 0;
			}
		}
		else {
			cout << vect[now].second;
			now = 0;
		}
	}
	return 0;
}


int main() {
	cout << "Hello! It's Huffman's algorithm demo program!\nTo continue select programm mode:\n1) Huffman's code generation\n2) Coding\n3) Decoding\n";
	int mode;
	cin >> mode;
	if (mode == 1) {
		generate();
	}
	else if (mode == 2) {
		code();
	}
	else {
		decode();
	}
	cout << "\nSee you next time!\n";
	return 0;
}