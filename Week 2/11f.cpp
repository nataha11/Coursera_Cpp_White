bool IsPalindrom(string s) {
	string tmp = s;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		if(s[i] != tmp[n - i - 1])
			return false;
	}
	return true;
}

vector<string> PalindromFilter(vector<string> v1, int minLength) {
	vector<string> v2;
	for(auto a : v1) {
		if(IsPalindrom(a) && a.size() >= minLength)
			v2.push_back(a);
	}
	return v2;
}