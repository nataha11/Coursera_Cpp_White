#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

void execute(map<set<string>, int>& routes) {
    int N;
    cin >> N;
    string stop;
    set<string> tmp;
    for(int i = 0; i < N; i++) {
        cin >> stop;
        tmp.insert(stop);
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
    map<set<string>, int> routes;
    for(int i = 0; i < Q; i++) {
        execute(routes);
    }

    return 0;
}