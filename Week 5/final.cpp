#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

bool EnsureNextSymbolAndSkip(stringstream& stream) {
    if (stream.peek() != '-') {
        return 0;
    }
    stream.ignore(1);
    return 1;
}

class Date {
public:
    Date(const string& new_date) {
        int new_year, new_month, new_day;
        stringstream stream(new_date);
        if(((stream >> new_year) && EnsureNextSymbolAndSkip(stream) && (stream >> new_month) && EnsureNextSymbolAndSkip(stream) && (stream >> new_day) && stream.eof()) == 0) {
            throw runtime_error("Wrong date format: " + new_date);
        } else if(new_month < 1 || new_month > 12) {
            throw runtime_error("Month value is invalid: " + to_string(new_month));
        } else if(new_day < 1 || new_day > 31) {
            throw runtime_error("Day value is invalid: " + to_string(new_day));
        } else {
            year = new_year;
            month = new_month;
            day = new_day;
        }
    }

    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if(lhs.GetYear() < rhs.GetYear())
        return 1;
    if(lhs.GetYear() == rhs.GetYear()) {
        if(lhs.GetMonth() < rhs.GetMonth())
            return 1;
        if(lhs.GetMonth() == rhs.GetMonth()) {
            if(lhs.GetDay() < rhs.GetDay())
                return 1;
        }
    }
    return 0;
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() << "-" << setw(2) << date.GetMonth() << "-" << setw(2) << date.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        database[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        int counter = 0;
        if(database.count(date) > 0 && database[date].count(event) > 0) {
            database[date].erase(event);
            return 1;
        }
        return 0;
    }
    int DeleteDate(const Date& date) {
        int N = 0;
        if(database.count(date) > 0) {
            N = database[date].size();
            database[date].clear();
        }
        return N;
    }

    void Find(const Date& date) const {
        try {
            for(auto& item : database.at(date)) {
                cout << item << endl;
            }
        }    
        catch (out_of_range& ex) {

        }    
    }

    void Print() const {
        for(const auto& item : database) {
            for(const auto& itemset : item.second) {
                cout << item.first << " " << itemset << endl;
            }
        }
    }

private:
    map<Date, set<string>> database;
};

void execute(const string& command_line, Database& db) {
    stringstream stream(command_line);
    string cmd;
    stream >> cmd;

    if(cmd == "Add") {
        string date, event;
        stream >> date;
        stream >> event;
        db.AddEvent(Date(date), event);

    } else if(cmd == "Del") {
        string date, event;
        stream >> date;
        if(stream >> event) {
            
            if(db.DeleteEvent(Date(date), event)) {
                cout << "Deleted successfully" << endl;
            } else {
                cout << "Event not found" << endl;
            }
        } else {
            int N = db.DeleteDate(Date(date));
            cout << "Deleted " << N << " events" << endl;
        }

    } else if(cmd == "Find") {
        string date;
        stream >> date;
        db.Find(Date(date));

    } else if(cmd == "Print") {
        db.Print();

    } else {
        throw runtime_error("Unknown command: " + cmd);
    }

}

int main() {
    Database db;
      
    string command_line;

    while (getline(cin, command_line)) {
        try {
            if(command_line != "") {
                execute(command_line, db);
            }
        } catch (runtime_error& ex) {
            cout << ex.what() << endl;
            return 1;
        }
    }

    return 0;
}