#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    double num;
    if(input) {
        cout << fixed << setprecision(3);
        while(input >> num) {
            cout << num << endl;
        }
    } else
        cout << "error" << endl;
    return 0;
}