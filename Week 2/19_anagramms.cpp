#include <iostream>
#include <map>
using namespace std;

map<char, int> MapCharCounter(const string& word) {
	map<char, int> counter;
	for (auto c : word) {
		counter[c]++;
	}
	return counter;
}

void IsAnagram(const string& word1, const string& word2) {
	if(MapCharCounter(word1) == MapCharCounter(word2))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;	
}

int main() {
	int N;
	string word1, word2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word1 >> word2;
		IsAnagram(word1, word2);		
	}


	return 0;
}