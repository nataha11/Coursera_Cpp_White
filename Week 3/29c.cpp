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