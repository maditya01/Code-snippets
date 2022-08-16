// calculate the sum of the digits of numbers 1 through n.
//1 2 3 4 ...10 11 12....100 101 102 Calculate Sum of Digits of a Number from 1 to n.

//Iska Tree Structure kaisa banega wo soach lo.

string n; 
int dp[10][90][2];
int helper(int  sum, int ind, bool last) {
 
	// cout << sum << " " << ind << " " << last << endl;
	if (ind == n.size()) {
		return sum;
	}
	// cout << dp[ind][sum][last] << " ";
	if (dp[ind][sum][last] != -1) return dp[ind][sum][last];
	int till = (last == true) ? n[ind] - '0' : 9;
	// cout << till << endl;
	int ans = 0;
 
	for (int i = 0; i <= till; i++) {
		ans += helper(sum + i, ind + 1, last && (i == till));
	}
	return dp[ind][sum][last] = ans;
}
 
int solve(int b) {
	n = to_string(b);
	memset(dp, -1, sizeof(dp));
	// cout << n << endl;
	return helper(0, 0, true);
}
 
 
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	fastio();
	int tc = 1;
//cin>>tc;
	while (true) {
		int a, b;
		cin >> a >> b;
 
		if (a == -1 and b == -1) break;
		cout << solve(b) - solve(a - 1) << endl;
	}
 
} 
