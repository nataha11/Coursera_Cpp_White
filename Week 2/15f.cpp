vector<int> Reversed(const vector<int>& v) {
	vector<int> w;
	int n = v.size();
	for (int i = 0; i < n; i++) {
			w.push_back(v[n - i - 1]);
		}	
	return w;	
}