#include <iostream>


using namespace std;



int gcd (int a, unsigned int b){

    if (0 == b) return a;

    return gcd (b, a%b);

};



struct Rational{

    int m;

    unsigned int n;

    Rational(int a, unsigned int b){

        m = a / gcd (a, b);

        n = b / gcd (a, b);

    }

    Rational (Rational &X){

        m = X.m;

        n = X.n;

    }


    Rational &operator*= (Rational &b){

        m *= b.m;

        n *= b.n;

        int g = gcd (m, n);

        m /= g;

        n /= g;

        return *this;

    }
    
    Rational &operator+= (Rational &b){

        m = m*b.n + n*b.m;

        n *= b.n;

        int g = gcd (m, n);

        m /= g;

        n /= g;

        return *this;

    }
    
    Rational &operator-= (Rational &b){

        m = m*b.n - n*b.m;

        n *= b.n;

        int g = gcd (m, n);

        m /= g;

        n /= g;

        return *this;

    }
    

    Rational &operator/= (Rational &b){

        m *= b.n;

        n *= b.m;

        int g = gcd (m, n);

        m /= g;

        n /= g;

        return *this;

    }

};







Rational operator* (Rational a, Rational &b){
    a *= b; 
    int g = gcd(a.m, a.n); 
    a.m /= g;
    a.n /= g;
    return a;
    

};


Rational operator+ (Rational a, Rational &b){
    a += b; 
    int g = gcd(a.m, a.n); 
    a.m /= g;
    a.n /= g;
    return a;
    

};

Rational operator- (Rational a, Rational &b){
    a -= b; 
    int g = gcd(a.m, a.n); 
    a.m /= g;
    a.n /= g;
    return a;
    

};


Rational operator/ (Rational a, Rational &b){

    a /= b;

    int g = gcd (a.m, a.n);

    a.m /= g;

    a.n /= g;

    return a;

};



bool operator> (Rational &a, Rational &b){

    return (a.m * b.n > a.n * b.m);

};



bool operator<= (Rational &a, Rational &b){

    return !(a > b);

};



bool operator< (Rational &a, Rational &b){

    return (a.m * b.n < a.n * b.m);

};



bool operator>= (Rational &a, Rational &b){

    return !(a < b);

};



bool operator== (Rational &a, Rational &b){

    return ((a.m == b.m) && (a.n == b.n));

};



ostream& operator<< (std::ostream& out, const Rational &a){

    return out << a.m << "/" << a.n;

};



istream& operator>> (std::istream& in, Rational &a){

    in >> a.m >> a.n;

    int g = gcd (a.m, a.n);

    a.m /= g;

    a.n /= g;

    return in;

};





int main()

{

    Rational num1(1,1), num2(1,1);

    cout << "Введите первое число:\n";

    cin >> num1;

    cout << "Введите второе число:\n";

    cin >> num2;
    cout << "Сумма:\n";
    cout << num1 + num2 << "\n";
    cout << "Разность:\n";
    cout << num1 - num2 << "\n";
    cout << "Произведение:\n";
    cout << num1 * num2 << "\n";
    cout << "Деление:\n";
    cout << num1 / num2 << "\n";
    cout << "Эквивалентность:\n";
    if (num1 == num2) cout << "Да\n";
    else cout << "Нет\n";
    cout << "Больше:\n";
    if (num1 > num2) cout << "Да\n";
    else cout << "Нет\n";
    cout << "Меньше:\n";
    if (num1 < num2) cout << "Да\n";
    else cout << "Нет\n";
    cout << "Больше или равно:\n";
    if (num1 >= num2) cout << "Да\n";
    else cout << "Нет\n";
    cout << "Меньше или равно:\n";
    if (num1 <= num2) cout << "Да\n";
    else cout << "Нет\n";
    return 0;

}

