#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

void execute(const string& cmd, map<string, set<string>>& dict) {
    if(cmd == "ADD") {
        string word1, word2;
        cin >> word1 >> word2;
        dict[word1].insert(word2);
        dict[word2].insert(word1);
        return;
    }

    if(cmd == "COUNT") {
        string word;
        cin >> word;
        cout << dict[word].size() << endl;
        return;
    }

    if(cmd == "CHECK") {
        string word1, word2;
        cin >> word1 >> word2;
        if(dict[word1].count(word2) > 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int Q;
    cin >> Q;
    string cmd;
    map<string, set<string>> dict;
    for(int i = 0; i < Q; i++) {
        cin >> cmd;
        execute(cmd, dict);
    }

    return 0;
}