#include <iostream>
using namespace std;

bool IsPalindrom(string s) {
	string tmp = s;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		if(s[i] != tmp[n - i - 1])
			return false;
	}
	return true;
}

int main() {
	string s;
	cin >> s;
	cout << IsPalindrom(s);

	return 0;
}
