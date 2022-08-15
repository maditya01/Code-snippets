// Return the knight's minimum initial health so that he can rescue the princess.
//Health can not be less than 0. at any point in time. itself at last cell atMin we have 1 value of health.
//initially knight is at top left cornor.
//knight can move in only 2 directions right and bottom  after seeing this you can apply bottom up approach 

class Solution {
public:
    int n,m;
    int calculateMinimumHP(vector<vector<int>>& d) {
     
    //in each path what is the minimum -ve  contigous sum can i get
    //in one path min-ve sm -10
    //in one path min -ve sm 
    //initially -ve health se deal karo.
     
         n=d.size();
         m=d[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        // dp[i][j] = min health points so that we can reach [n-1][m-1] from [i,j];
        int sm=0;
        for(int j=m-1;j>=0;j--){
            sm += d[n-1][j];
            dp[n-1][j] = sm<0?(sm*-1)+1:1;// i am putting 1 because it can't be zero.
           //because minimum initial health can be 1 not zero because 0 is not allowed so if continuous sum is greater than zero 
           //then minimum initial health can be 1.
           //if continuous sum is less than zero then minimum initial health is (sm*-1)+1.         
            if(sm>0) sm=0;
        }
        sm=0;
        for(int j=n-1;j>=0;j--){
            sm += d[j][m-1];
            dp[j][m-1] = sm<0?(sm*-1)+1:1;
                if(sm>0) sm=0;
        }
       for(int i=n-2;i>=0;i--){
           for(int j=m-2;j>=0;j--){
               int c1= dp[i+1][j];
               int c2= dp[i][j+1];
               int c3= 1- min(c1,c2);
                int sum= d[i][j]+c3;
               dp[i][j] = sum>0?1:(sum*-1)+1;
           }
       } 
        
       return dp[0][0];
              
    }
};
