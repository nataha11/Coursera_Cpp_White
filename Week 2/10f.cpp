bool IsPalindrom(string s) {
	string tmp = s;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		if(s[i] != tmp[n - i - 1])
			return false;
	}
	return true;
}