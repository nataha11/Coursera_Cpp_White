#include <iostream>
using namespace std;

int Factorial(int x) {
    if(x < 0)
        return 1;
	int f = 1;
	for(int i = x; i > 0; i--) {
		f *= i;
	}
	return f;
}

int main() {
	int n;
	cin >> n;
	cout << Factorial(n);

	return 0;
}
