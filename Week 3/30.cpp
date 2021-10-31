#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct name {
    string firstn;
    string secondn;
};
typedef struct name Name;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        history[year].firstn = first_name;

    }
    void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
        history[year].secondn = last_name;
    }
    
    string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
        string name1 = history[year].firstn;
        string name2 = history[year].secondn;
        //cout << "Start: name1 = " << name1 << ", name2 = " << name2 << endl;
        
        for(auto i : history) {
            if(i.first <= year) {// в map элементы хранятся отсортированно, поэтому закончим на ближайшей записи в истории изменении
                if(i.second.firstn != "")
                    name1 = i.second.firstn;
                if(i.second.secondn != "")
                    name2 = i.second.secondn;
            }

        }
        //cout << "Got: name1 = " << name1 << ", name2 = " << name2 << endl;
        if(name1 == "" && name2 == "")
            return "Incognito";
        if(name1 != "" && name2 == "") {
            return name1 + " with unknown last name";
        }
        if(name1 == "" && name2 != "") {
            return name2 + " with unknown first name";
        }
        
        return name1 + " " + name2;
    }
private:
    map<int, Name> history;


};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
    cout << year << ": " << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
    cout << year << ": " << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
    cout << year << ": " << person.GetFullName(year) << endl;
    }

  return 0;
}