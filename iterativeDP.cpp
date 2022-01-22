// How to Think in terms of iterative
// How to Think DP problem in Terms of State and Transition

Here we are thinking in term of DP state
what dp[i]-> telling ,what dp[i][j]-> telling ...etc 

What is the Transition from one DP state to another
dp[i]=dp[i-x]+something like that dp[i][j]= dp[i-1][j]+ dp[i-1][j-nums[i-1]] something like that


//what is the answer of smallest DP state which you can directly tell  like dp[0]=something dp[n] =something dp[0][0]=something 


//One question comes when you write Iterative DP where you have to start-> then your smallest DP state would be helpFull.
