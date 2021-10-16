#include <iostream>
#include <map>
using namespace std;

void execute(const string& cmd, map<string, string>& cap) {
	if (cmd == "DUMP") {
		if(cap.size() == 0)
			cout << "There are no countries in the world" << endl;
		for (auto pair : cap) {
			cout << pair.first << "/" << pair.second << " ";
		}
		return;
	}

	string country;
	cin >> country;

	if(cmd == "ABOUT") {
		string tmp = cap[country];//cap[country] == capital
		if (tmp == "") {
			cout << "Country " << country << " doesn't exist" << endl;
			cap.erase(country);
		} else
			cout << "Country " << country << " has capital " << cap[country] << endl; 
		return;
	}

	string newname;
	cin >> newname;

	if(cmd == "RENAME") {
		bool flag = 0;
		if (country == newname) {
			flag = 1;
		} else if (cap[country] == "") {
			cap.erase(country);
			flag = 2;
		} else if (cap[newname] == "") {
			cout << "Country " << country << " with capital " << cap[country] << " has been renamed to " << newname << endl;	    
		    cap[newname] = cap[country];
		    cap.erase(country);
		    return;

		}
		cout << "Incorrect rename, skip" << endl;
		return;
	}

	if(cmd == "CHANGE_CAPITAL") {
		if (cap[country] == "") {
			cap[country] = newname;
			cout << "Introduce new country " << country << " with capital " << newname << endl;
		} else if (cap[country] == newname) {
			cout << "Country " << country << " hasn't changed its capital" << endl;
		} else {
			cout << "Country " << country << " has changed its capital from " << cap[country] << " to " << newname << endl;
			cap[country] = newname;

		}
		return;
	}

}


int main() {
	int Q;
	cin >> Q;
	string cmd;
	map<string, string> cap;	
	for(int i = 0; i < Q; i++) {
	    cin >> cmd;
	    execute(cmd, cap);
	}

	return 0;
}