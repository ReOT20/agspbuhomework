#include <iostream>
using namespace std;


struct Node {
	int data;
	Node* next = NULL;
};


struct Stack {
	Node* head = NULL;

	Stack() {}

	Stack(int x) {
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

	int pop() {
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
	Stack a;
	a.push(13);
	std::cout << a.pop();
	return 0;
}