// ONE TO ONE CHOICES +  Factorial Type Condition banne Chahiye.

// mask represents what elements you have taken what not taken ->    011001011 0th you have not taken 1st you have taken 2nd you have taken 3rd you don't and so on. 

// dp(i,mask)-> Typical DP State


//Ak variable ko Mask me convert karo
//Ak variable ko lekar iterate karo.

// iterate over mask and check if it is assign before or not if not assign then assign ith element include your cost move next ith element with updated mask

//we have (i,mask)
int func(int i, int mask, int n) {
	if (i >= n) return 0;

	if (dp[i][mask] != -1) return dp[i][mask];
//jth people ko ith job assign kar do.
	 int ans = INT_MAX;
  //Iterate over mask
	for (int j = 0; j < n; j++) {
		//if jth person ko assign nhi hua hai
		if (mask & (1 << j)) {
			ans = min(ans, cost[i][j] + func(i + 1, mask ^ (1 << j), n));
		}
	}
	ans=min(ans,func(i+1,mask,n)//Not assigning any work at ith position.
	return dp[i][mask] = ans;
}
