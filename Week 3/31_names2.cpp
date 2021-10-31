#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
  string name;
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
      name = item.second;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }
  
  return name;
}

 vector<string> FindHistoryByYear(const map<int, string>& names, int year) {
  vector<string> res;
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
      if(res.empty())
        res.push_back(item.second);
      else if(res[res.size() - 1] != item.second)
        res.push_back(item.second);
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }

  return res;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }
  string GetFullName(int year) {
    // получаем имя и фамилию по состоянию на год year
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
    
    // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    
    // если неизвестно только имя
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
      
    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
      
    // если известны и имя, и фамилия
    } else {
      return first_name + " " + last_name;
    }
  }
  string GetFullNameWithHistory(int year) {
  // получить все имена и фамилии по состоянию на конец года year
    vector<string> first_history_v = FindHistoryByYear(first_names, year);//all history including current name
    vector<string> last_history_v = FindHistoryByYear(last_names, year);

    string first_name = "";
    if(first_history_v.empty() == 0) {
      first_name = first_history_v[first_history_v.size() - 1];
      first_history_v.pop_back();
      reverse(first_history_v.begin(), first_history_v.end());    
    }

    string last_name = "";
    if(last_history_v.empty() == 0) {
      last_name = last_history_v[last_history_v.size() - 1];
      last_history_v.pop_back();//erase current name from history vector 
      reverse(last_history_v.begin(), last_history_v.end());       
    }


    string first_history = "";
    if(first_history_v.empty() == 0) {
      first_history = " (";
      for(const auto& item : first_history_v) {
        first_history = first_history + item + ", ";
      }
      first_history.pop_back();//erase " "
      first_history.pop_back();//erase ","
      first_history = first_history + ")";
    }
    
    string last_history = "";
    if(last_history_v.empty() == 0) {
      last_history = " (";
      for(const auto& item : last_history_v) {
        last_history = last_history + item + ", ";
      }
      last_history.pop_back();//erase " "
      last_history.pop_back();//erase ","
      last_history = last_history + ")";
    }


        // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    
    // если неизвестно только имя
    } else if (first_name.empty()) {
      return last_name + last_history + " with unknown first name";
      
    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name + first_history + " with unknown last name";
      
    // если известны и имя, и фамилия
    } else {
      return first_name + first_history + " " + last_name + last_history;
    }
  } 

private:
  map<int, string> first_names;
  map<int, string> last_names;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeFirstName(1965, "Appolinaria");

  person.ChangeLastName(1965, "Sergeeva");
  person.ChangeLastName(1965, "Volkova");
  person.ChangeLastName(1965, "Volkova-Sergeeva");

  for (int year : {1964, 1965, 1966}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}

