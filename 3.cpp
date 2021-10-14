#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double d = b * b - 4 * a * c;
	if (a != 0) {
		if  (d >= 0) {
			double x1 = ((-1) * b + sqrt(d))/(2 * a);
			double x2 = ((-1) * b - sqrt(d))/(2 * a);
			if (x1 != x2) {
				cout << x1 << ' ' << x2;
			} else {
				cout << x1;
			}
		}
	} else if (b != 0){
		cout << (-1) * c / b;
	}

	return 0;
}
