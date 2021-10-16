#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void execute(map<vector<string>, int>& routes) {
    int N;
    cin >> N;
    string stop;
    vector<string> tmp;
    for(int i = 0; i < N; i++) {
        cin >> stop;
        tmp.push_back(stop);
    }

    if(routes.count(tmp) != 0) {
        cout << "Already exists for " << routes[tmp] << endl;
        return;
    }
    
    
    int s = routes.size();
    routes[tmp] = s + 1;
    cout << "New bus " << routes[tmp] << endl;
}

int main() {
    int Q;
    cin >> Q;
    map<vector<string>, int> routes;
    for(int i = 0; i < Q; i++) {
        execute(routes);
    }

    return 0;
}