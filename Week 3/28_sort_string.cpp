#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void print(const vector<string>& v) {
    for(auto i : v) {
        cout << i << " ";
    }
}

string low(string& s) {
    for(auto& i : s) {
        i = tolower (i);
    }
    return s;
}

int main() {
    int N;
    cin >> N;
    vector<string> v;
    string a;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        v.push_back(a);
    }
    sort(begin(v), end(v), [](string x, string y) {
        x = low(x);
        y = low(y);
        return (x < y);
    });
    print(v);

    return 0;
}