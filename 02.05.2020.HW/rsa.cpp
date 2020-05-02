#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;


int gcd(int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}


bool isprime(int n) {
	int c = 0;
	for (int i = sqrt(n) + 1; i > 1; i--) {
		if (n % i == 0) {
			c++;
		}
	}
	return c;
}


int generate() {
	cout << "To genrate keys give me two prime numbers.\nRemember that maximum value that you will be able to code/decode is their product - 1\n";
	int p, q;
	cin >> p >> q;
	int x, y, m, a;
	m = (p - 1) * (q - 1);
	srand(time(NULL));
	int e = (rand()%m-1)+1;
	while (isprime(e)) {
		e = (rand()%m-1)+1;
	}
    int g = gcd (e, m, x, y);
	cout << "Here are your keys:\nPublic key n: " << p * q << "\nPublic key e: " << e << "\nPrivate key d: " << (x % m + m) % m << "\n";
	return 0; 
}


int code() {
	cout << "To code data input data and keys in order public key e, public key n, number\n";
	int m, e, n;
	cin >> e >> n >> m;
	cout << "Your coded data:\n" << ((m % n)^e)%n << "\n";
	return 0;
}


int decode() {
	cout << "To decode data input data and keys in order private key d, public key n, number\n";
	int m, e, n;
	cin >> e >> n >> m;
	cout << "Your coded data:\n" << ((m % n)^e)%n << "\n";
	return 0;
}


int main() {
	cout << "Hello! It's RSA algorithm demo program.\nPlease select working mode:\n1) Generating keys\n2) Coding\n3) Decoding\n";
    int x;
	cin >> x;
	if (x == 1) {
		generate();
	} else if (x == 2) {
		code();
	} else {
		decode();
	}
    return 0;
}