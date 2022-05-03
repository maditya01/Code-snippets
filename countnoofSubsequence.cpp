//Count Number of Subsequences of legth k with some property.

//subsequence ends at ith index ka concept lagega.

// dp[i][j]=dp[i-1][j-1]+dp[i-2][j-1]+dp[i-3][j-1]+dp[i-4][j-1]......

//length = 1 is your base case. for all index.
for(int i=0;i<n;i++){
//Length 1 
}
for(int i=1;i<n;i++){
 
  for(int len=2;len<=k;len++){
    
    for(int ind=i-1;ind>=0;ind--){
      //according to property check nums[i] with nums[ind] and take with len-1 prev DP state
      
    }
    
  }
}
