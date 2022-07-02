//Pattern Searching Algorithms 
// We are given string S,string P we want to search string P in to String S in O(N) Time.
//Brute Force Approach is O(N^2) sliding window approach.

//Calculation of prefix Function.
vector<int> prefixFunction(string s) {
	vector<int> pi(s.size(), 0);
	for (int i = 1; i < s.size(); i++) {
		int j = pi[i - 1];
		//this is important.
		while (j > 0 and s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		pi[i] = j;
	}
	return pi;
}




















