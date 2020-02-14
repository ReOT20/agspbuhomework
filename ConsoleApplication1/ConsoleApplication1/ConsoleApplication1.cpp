#include <iostream>
#include <string>
using namespace std;


struct Node {
	char data;
	Node* next = NULL;
};


struct Stack {
	Node* head = NULL;

	Stack() {}

	Stack(char x) {
		head = new Node;
		head->data = x;
	}

	void push(int a) {
		if (head == NULL) {
			head = new Node;
			head->data = a;
			return;
		}
		Node* temp = new Node;
		temp->data = a;
		temp->next = head;
		head = temp;
	}

	char pop() {
		Node* temp = head;
		head = head->next;
		int a = temp->data;
		delete temp;
		return a;
	}
	~Stack() {
		while (head != NULL) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};


int main() {
	Stack st;
	string input;
	cin >> input;
	int n = input.length();
	for (int i = 0; i < n; i++) {
		st.push(input[i]);
	}
	int parentheses_bracket_1 = 0;
	int parentheses_bracket_2 = 0;
	int square_bracket_1 = 0;
	int square_bracket_2 = 0;
	int curly_bracket_1 = 0;
	int curly_bracket_2 = 0;
	int angle_bracket_1 = 0;
	int angle_bracket_2 = 0;
	int i = 0;
	bool check = true;
	char temp;
	while (i < n && check) {
		temp = st.pop();
		if (temp == ')')
			parentheses_bracket_1 += 1;
		else if (temp == '(')
			parentheses_bracket_2 += 1;
		else if (temp == ']')
			square_bracket_1 += 1;
		else if (temp == '[')
			square_bracket_2 += 1;
		else if (temp == '}')
			curly_bracket_1 += 1;
		else if (temp == '{')
			curly_bracket_2 += 1;
		else if (temp == '>')
			angle_bracket_1 += 1;
		else if (temp == '<')
			angle_bracket_2 += 1;
		if (parentheses_bracket_2 > parentheses_bracket_1 || 
			square_bracket_2 > square_bracket_1 || 
			curly_bracket_2 > curly_bracket_1 || 
			angle_bracket_2 > angle_bracket_1)
			check = false;
		else
			i += 1;
	}
	if (i == n)
		cout << "Right!";
	else
		cout << "Wrong!";
	return 0;
}