#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Student {
    string fname;
    string lname;
    int day;
    int month;
    int year;
};

void execute(const string& request, int k, const vector<Student>& students) {

    if(request == "name")
        cout << students[k].fname << " " << students[k].lname << endl;
    else if(request == "date")
        cout << students[k].day << "." << students[k].month << "." << students[k].year << endl;
    else
        cout << "bad request" << endl;
}

int main() {
    int N;
    cin >> N;

    vector<Student> students(N);
    for (int i = 0; i < N; i++) {
        cin >> students[i].fname;
        cin.ignore(1);
        cin >> students[i].lname;
        cin.ignore(1);
        cin >> students[i].day;
        cin.ignore(1);
        cin >> students[i].month;
        cin.ignore(1);
        cin >> students[i].year;        
    }

    int M;
    cin >> M;
    string request;
    int k = -1;
    for (int j = 0; j < M; j++) {
        cin >> request;
        cin.ignore(1);
        cin >> k;
        if(k < 1 || k > N)
            cout << "bad request" << endl;
        else
            execute(request, k - 1, students);
            
    }

    return 0;
}