void MoveStrings(vector<string>& src, vector<string>& dst) {
	for(auto i : src) {
		dst.push_back(i);
	}
	src.clear();
}