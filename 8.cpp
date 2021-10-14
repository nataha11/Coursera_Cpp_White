#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> number;
	while (n > 0) {
		number.push_back(n % 2);
		n /= 2;
	}
	for (int i = number.size() - 1; i >= 0; i--) {
	    cout << number[i];
	}

	return 0;
}
