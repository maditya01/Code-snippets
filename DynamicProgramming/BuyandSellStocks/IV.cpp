//
//
// Find the maximum profit you can achieve. You may complete at most k transactions.
// 

class Solution {
public:
    int dp[1001][2][101];

  //trans=0 means you have bought the stocks but you don't have selle the stock
  //trans==1 means you have nothing at current time. means you don't have any transaction 
  
  //what we are passing in function is important.
   int solve(int curr, int i,bool trans,int k,vector<int>& prices){
        // cout<<curr<<" "<<"i->"<<i<<" k->"<<k<<" trans->"<<trans<<endl;        
        if(i>=prices.size()) return 0;
        if(k<=0) return  0;
        // return condition must 
       if(dp[i][trans][k]!=-1 and trans==1) return dp[i][trans][k];
      
        //at ith index you have 3 choices 
        //either you buy,or you sell or you do nothing
        //you can buy 
      return dp[i][trans][k] = max(solve(curr,i+1,trans,k,prices),    
        (trans==1)? solve(prices[i],i+1,0,k,prices): (prices[i]-curr) + solve(0,i+1,1,k-1,prices));
    }
    
    int maxProfit(int k, vector<int>& prices) {
       memset(dp,-1,sizeof(dp));
        //dp[i][j][k]-> Maximum Profit by taking first i items
        //j-> Buy or Sell
        //k-> Number of transactions
        //subarray i...j ka maximum Profit kya hai
        return solve(0,0,1,k,prices);
    }
};
