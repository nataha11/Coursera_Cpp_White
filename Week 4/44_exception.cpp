#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>
#include <exception>

using namespace std;

int gcd(int a , int b) {
    if(b == 0)
        return a;
    a %= b;
    return gcd(b,a);
}

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        if(denominator == 0) {
            throw invalid_argument("invalid_argument");
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

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if(rhs.Numerator() == 0)
        throw domain_error("domain_error");
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

istream& operator>>(istream& stream, Rational& rational) {
    int n, d;
    char c;
    if(stream >> n && stream >> c) {
        if(c != '/')
            return stream;
        if(stream >> d)
            rational = Rational(n, d);
        
    }
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

bool operator>(Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}
bool operator<(Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
