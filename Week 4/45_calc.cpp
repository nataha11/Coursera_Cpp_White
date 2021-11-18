#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <sstream>
#include <numeric>//from C++17, gcd

using namespace std;

/*int gcd(int a , int b) {
    if(b == 0)
        return a;
    a %= b;
    return gcd(b,a);
}*/

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        if(denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        if(denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }
        num = numerator / gcd(numerator, denominator);
        den = denominator / gcd(numerator, denominator);
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return den;
    }

private:
    int num;
    int den;
};

bool operator ==(const Rational& lhs, const Rational& rhs) {
    return(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

Rational operator +(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator -(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator *(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator /(const Rational& lhs, const Rational& rhs) {
    if(rhs.Numerator() == 0)
        throw domain_error("Division by zero");
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

istream& operator >>(istream& stream, Rational& rational) {
    int n, d;
    char c;
    if (stream) {
        stream >> n >> c >> d;
        if (stream && (c == '/')) {
            rational = Rational(n, d);
          
        }
    }
    return stream;
}

ostream& operator <<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

bool operator >(Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}
bool operator <(Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}

Rational calculate(const Rational& r1, const Rational& r2, const char operation) {
    switch(operation) {
        case '+': return r1 + r2;
        case '-': return r1 - r2;
        case '*': return r1 * r2;
        case '/': return r1 / r2;
        default: {
            throw invalid_argument("Invalid operation");
            return Rational(55555, 1);
        }
    };
}

int main() {
    Rational r1, r2;
    char operation;
    try {
        cin >> r1 >> operation >> r2;
        //cout << r1 << " " << operation << " " << r2 << endl;
        cout << calculate(r1, r2, operation) << endl;
    } catch(const exception& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}

