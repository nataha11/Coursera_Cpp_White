#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");

    int N = 0;
    int M = 0;

    if(input) {
        input >> N;
        input >> M;

        int x = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                input >> x;
                input.ignore(1);
                cout << setw(10);
                cout << x;
                if(j != M - 1)        
                    cout << " ";
                else if(i != N - 1)
                    cout << endl;
            } 
        }
        
    } else
        cout << "error" << endl;
    return 0;
}