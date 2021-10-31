#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void print(const vector<int>& v) {
    for(auto i : v) {
        cout << i << " ";
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> v;
    int a;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        v.push_back(a);
    }
    sort(begin(v), end(v), [](int x, int y) {
        return (abs(x) < abs(y));
    });
    print(v);

    return 0;
}