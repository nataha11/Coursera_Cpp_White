#include <iostream>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& src, vector<string>& dst) {
	for(auto i : src) {
		dst.push_back(i);
	}
	src.clear();
}


int main() {
	vector<string> source = {"a", "b", "c"};
	vector<string> destination = {"z"};
	MoveStrings(source, destination);
	// source должен оказаться пустым
	//destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
    for(auto i : destination) {
        cout << i;
    }

	return 0;
}
