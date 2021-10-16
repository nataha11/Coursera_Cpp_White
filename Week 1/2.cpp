#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	string tmp;
	if (a < b) {
		tmp = a;
	} else {
		tmp = b;
	}

	if (tmp < c) {
		cout << tmp;
	} else {
		cout << c;
	}
	return 0;
}



