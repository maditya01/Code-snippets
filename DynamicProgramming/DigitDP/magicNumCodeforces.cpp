//When  Differentiates with position like even position par ye odd position par ye 
//then wha par if else laga kar samabhal lo.
//Sum of Digits Is Multiple of m or not. (sum_mod*10+digit)%m.

int m, d;
string a, b;
string s;
int mod = 1e9 + 7;
int dp[2001][2][2001];
int fun(int ind, bool last, int sum_mod) {
	if (ind == s.size()) {
		if (sum_mod == 0) {
			return 1;
		}
		return 0;
	}
	if (dp[ind][last][sum_mod] != -1) return dp[ind][last][sum_mod];
	int till = (last == true) ? (s[ind] - '0') : 9;
	int ans = 0;
 
	if (ind % 2 == 1) {
		//Even Position we can place only D.
		if (till >= d) {
			ans = (ans * 1LL + fun(ind + 1, last && d == till, (sum_mod * 10 + d) % m) * 1LL);
			ans %= mod;
		}
	} else {
		//odd Position
		for (int k = 0; k <= till; k++) {
			if (k != d) {
				ans = (ans * 1LL + fun(ind + 1, last && k == till , (sum_mod * 10 + k) % m) * 1LL);
				ans %= mod;
			}
		}
	}
	return dp[ind][last][sum_mod] = ans;
}
 
int solve(string _n) {
	s = (_n);
	// cout << s.size() << endl;
	memset(dp, -1, sizeof(dp));
	// cout << s << endl;
	return fun(0, true, 0);
}
