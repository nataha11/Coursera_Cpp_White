#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
	vector<int> w = v;
	int n = v.size();
	for (int i = 0; i < n; ++i) {
			v[i] = w[n - i - 1];
		}	
}


int main() {
	vector<int> numbers = {1, 5, 3, 4, 2};
	Reverse(numbers);
	// numbers должен оказаться равен {2, 4, 3, 5, 1}
	for(auto i : numbers) {
		cout << i;
	}

	return 0;
}
