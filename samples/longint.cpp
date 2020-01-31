#include <iostream> 
#include <string> 

using namespace std;


unsigned long max(unsigned long a, unsigned long b) {
	if (a >= b) return a;
	return b;
}


struct longint {

	short* m;
	bool plus = true;
	unsigned long l;

	longint() {}

	longint(short* a, unsigned long b, bool c) {
		m = a;
		l = b;
		plus = c;
	}

	longint(unsigned long b, bool c) {
		l = b;
		m = new short[l];
		plus = c;
	}

	longint(string s) {
		l = s.length();
		unsigned long i = 0;
		if (s[0] == '-') {
			plus = false;
			l--;
			i++;
		}
		m = new short[l];
		if (plus) {
			while (i < l) {
				m[i] = short(s[i] - '0');
				i++;
			}
		}
		else {
			while (i < l + 1) {
				m[i - 1] = short(s[i] - '0');
				i++;
			}
		}
	}

	longint(const longint& a) {
		l = a.l;
		plus = a.plus;
		unsigned long i = 0;
		m = new short[l];
		while (i < l) {
			m[i] = a.m[i];
			i++;
		}
	}

	~longint() {
		delete[] m;
	}


	longint& operator= (longint& b) {
		plus = b.plus;
		if (m) {
			delete[] m;
			m = new short[l];
		}
		if (l != b.l) {
			l = b.l;
			m = new short[l];
		}
		unsigned long i = 0;
		while (i < l) {
			m[i] = b.m[i];
			i++;
		}
		return *this;
	}


	longint& operator+= (longint& b) {
		longint a(*this);
		if (plus == b.plus) {
			if (l > b.l) l++;
			else l = b.l + 1;
			m = new short[l];
			int i = 0;
			while (i < l) {
				m[i] = 0;
				i++;
			}
			i = l - 1;
			while (i > 0) {
				if (i - l + a.l > 0) {
					m[i] += a.m[i - l + a.l];
				}
				if (i - l + b.l > 0) {
					m[i] += b.m[i - l + b.l];
				}
				if (m[i] > 9) {
					m[i - 1] = m[i] / 10;
					m[i] %= 10;
				}
				i--;
			}
		}
		return *this;
	}
};


istream& operator>> (std::istream& in, longint& a) {
	string s;
	in >> s;
	a.l = s.length();
	unsigned long i = 0;
	if (s[0] == '-') {
		a.plus = false;
		a.l--;
		i++;
	}
	a.m = new short[a.l];
	if (a.plus) {
		while (i < a.l) {
			a.m[i] = short(s[i] - '0');
			i++;
		}
	}
	else {
		while (i < a.l + 1) {
			a.m[i - 1] = short(s[i] - '0');
			i++;
		}
	}
	return in;
}

ostream& operator<< (std::ostream& out, longint a) {
	unsigned long i = 0;
	if (!a.plus) out << '-';
	while (i < a.l) {
		out << a.m[i];
		i++;
	}
	return out;
}


longint& operator+ (longint& a, longint& b) {
	longint c;
	unsigned long i;
	if ((a.plus && b.plus) || (!a.plus && !b.plus)) {
		c.l = max(a.l, b.l) + 1;
		c.m = new short[c.l];
		c.plus = a.plus;
		c.m[0] = 0;
		i = 1;
		if (a.l >= b.l) {
			while (i < c.l) {
				c.m[i] = a.m[i - 1];
				i++;
			}
			i = c.l - 1;
			while (i >= c.l - b.l) {
				c.m[i] += b.m[i - c.l + b.l];
				if (c.m[i] > 10) {
					c.m[i - 1] += c.m[i] / 10;
					c.m[i] %= 10;
				}
				i--;
			}
		}
	}
	if (c.m[0] == 0) {
		longint d(c);
		d.l--;
		d.m = new short[d.l];
		i = 0;
		while (i < d.l) {
			d.m[i] = c.m[i + 1];
			i++;
		}
		return d;
	}
	return c;
}


bool operator> (longint& a, longint& b) {
	if (a.plus && !b.plus) return true;
	if (b.plus && !a.plus) return false;
	if (a.plus) {
		if (a.l > b.l) return true;
		if (a.l < b.l) return false;
		unsigned long i = 0;
		while (i < a.l) {
			if (a.m[i] > b.m[i]) return true;
			i++;
		}
		return false;
	}
	else {
		if (a.l < b.l) return true;
		if (a.l > b.l) return false;
		unsigned long i = 0;
		while (i < a.l) {
			if (a.m[i] < b.m[i]) return true;
			i++;
		}
		return false;
	}
}


bool operator< (longint& a, longint& b) {
	if (a.plus && !b.plus) return false;
	if (b.plus && !a.plus) return true;
	if (b.plus) {
		if (a.l < b.l) return true;
		if (a.l > b.l) return false;
		unsigned long i = 0;
		while (i < a.l) {
			if (a.m[i] < b.m[i]) return true;
			i++;
		}
		return false;
	}
	else {
		if (a.l > b.l) return true;
		if (a.l < b.l) return false;
		unsigned long i = 0;
		while (i < a.l) {
			if (a.m[i] > b.m[i]) return true;
			i++;
		}
		return false;
	}
}


bool operator== (longint& a, longint& b) {
	if (a.plus && !b.plus) return false;
	if (b.plus && !a.plus) return false;
	if (a.l != b.l) return false;
	unsigned long i = 0;
	while (i < a.l) {
		if (a.m[i] != b.m[i]) return false;
		i++;
	}
	return true;
}


bool operator!= (longint& a, longint& b) {
	return !(a == b);
}


bool operator<= (longint& a, longint& b) {
	return !(a > b);
}


bool operator>= (longint& a, longint& b) {
	return !(a < b);
}


int main() {
	longint num1, num2, num3;
	cin >> num1 >> num2;
	num2 += num1;
	cout << num2;
	return 0;
}