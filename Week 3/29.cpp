#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        our_strings.push_back(s);
    }

    vector<string> GetSortedStrings() {
        sort(begin(our_strings), end(our_strings));
        return our_strings;
    }
    
private:
    vector<string> our_strings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);
  
  return 0;
}