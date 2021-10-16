#include <iostream>
#include <vector>
using namespace std;

int get_month_size(int& month) {
    switch(month) {
        case 0:
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10: {
            return 31;
        }
        case 2: {
            return 28;
        }
        case 4:
        case 6:
        case 9:
        case 11: {
            return 30;
        }
        default:
            return month;
    }
}

void command(const string& operation, vector<vector<string>>& cases_in_month, int& month) {
	if(operation == "NEXT") {
	    int size = get_month_size(month);
        month = (month + 1) % 12; //нулевой месяц - декабрь
        int newsize = get_month_size(month);
        if(newsize < size) {
            for(int i = newsize; i < size; i++) {
                cases_in_month[newsize - 1].insert(end(cases_in_month[newsize - 1]), begin(cases_in_month[i]), end(cases_in_month[i]));
            }
        }
        cases_in_month.resize(newsize);
        return;
	}
	
	int i;
	cin >> i;
	if(operation == "DUMP") {
	    cout << cases_in_month[i - 1].size() << " ";
		for(auto j : cases_in_month[i - 1]) {  //j = vector<string>
			cout << j << " ";
		}
		cout << endl;
		return;
	}
	
	if(operation == "ADD") {
		string s;
		cin >> s;
		cases_in_month[i - 1].push_back(s);
		return;
	}
}


int main() {
    int q;
	cin >> q;
	vector<vector<string>> cases_in_month(31);
	int month = 1; //January
	string operation;
	for(int i = 0; i < q; i++) {
		cin >> operation;
		command(operation, cases_in_month, month);
	}
	return 0;
}
