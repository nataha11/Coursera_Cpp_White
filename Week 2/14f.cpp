void Reverse(vector<int>& v) {
	vector<int> w = v;
	int n = v.size();
	for (int i = 0; i < n; ++i) {
			v[i] = w[n - i - 1];
		}	
}
