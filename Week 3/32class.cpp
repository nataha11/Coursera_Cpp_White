#include <bits/stdc++.h>

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(const string& w) {
        str = w;
    }
    void Reverse() {
        reverse(str.begin(), str.end());
    }
    string ToString() const{
        return str;
    }
private:
    string str;
};