#include <iostream>
#include <vector>
using namespace std;


vector<int> Reversed(const vector<int>& v) {
	vector<int> w;
	int n = v.size();
	for (int i = 0; i < n; i++) {
			w.push_back(v[n - i - 1]);
		}	
	return w;	
}


int main() {
	vector<int> numbers = {1, 5, 3, 4, 2};
	vector<int> w = Reversed(numbers);
	// numbers должен оказаться равен {2, 4, 3, 5, 1}
	for(auto i : w) {
		cout << i;
	}

	return 0;
}
