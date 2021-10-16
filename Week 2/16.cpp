#include <iostream>
#include <vector>
using namespace std;

void printvector(const vector<int>& final) {
    for(auto l : final) {
		cout << l << " ";
	}
}

int main() {

	int n;
	cin >> n;

	vector<int> days_temp(n);
	int sum = 0;
	for(int t = 0; t < n; t++) {
		cin >> days_temp[t];
		sum += days_temp[t];
	}

	int average = sum / n;
	vector<int> final;
	int k = 0;
	for(int i = 0; i < n; i++) {
		if(days_temp[i] > average) {
			final.push_back(i);
			k++;
		}
	}

    cout << k << endl;
	printvector(final);

	return 0;
}
