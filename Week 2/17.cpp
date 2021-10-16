#include <iostream>
#include <vector>
using namespace std;

void update(vector<int>& queue, string& operation, int num) {
	if(operation == "COME") {
		queue.resize(queue.size() + num);
		return;
	}
	if(operation == "WORRY") {
		queue[num] = 1;
		return;
	}
	if(operation == "QUIET") {
		queue[num] = 0;
		return;
	}
}

void printworrycount(vector<int>& queue) {
	int count = 0;
	for(auto i : queue) {
		if(i == 1)
			count++;
	}
	cout << count << endl;
	return;    
}

int main() {

	int q;
	cin >> q;
	vector<int> queue;
	string operation;
	int num;
	for(int i = 0; i < q; i++) {
		cin >> operation;
		if(operation == "WORRY_COUNT") {
		    printworrycount(queue);
		} else {
		    cin >> num;
		    update(queue, operation, num);
	    }
	}
	return 0;
}
