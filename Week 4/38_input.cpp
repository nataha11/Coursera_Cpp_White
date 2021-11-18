#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream input("input.txt");
    string line;
    if(input) {
        while(getline(input, line)) {
            cout << line << endl;
        }
    } else
        cout << "error" << endl;
    return 0;
}