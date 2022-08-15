//Maximum Number of cherries You can Collect by moving from top to bottom and again from bottom to top.

//Rather than trying from bottom to top what you can do you take 2 people at top left cornor and try to move these two people in 4 direction
class Solution {
public:
    int n;
    int dp[51][51][51][51];
    int solve(int i1,int j1,int i2,int j2,vector<vector<int>>& grid){
        if(i1>=n or j1>=n or i2>=n or j2>=n or grid[i1][j1]==-1 or grid[i2][j2] == -1) return -int(1e8);
        if(i2==n-1 and j2==n-1) return grid[i2][j2];
        if(i1==n-1 and j1==n-1) return grid[i1][j1];
        if(dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];
        //this is important. taking the values of cells.
        int  val= grid[i1][j1]+grid[i2][j2];
       //if they are overlapping 
        if(i1==i2 and j1==j2){
           if(val==2) val--;
        }
      int c1 =  solve(i1+1,j1,i2+1,j2,grid);
      int c2 = solve(i1+1,j1,i2,j2+1,grid);
      int c3 = solve(i1,j1+1,i2+1,j2,grid);
      int c4 = solve(i1,j1+1,i2,j2+1,grid);
        val+=max({c1,c2,c3,c4});
        // cout<<val<<endl;
      return dp[i1][j1][i2][j2] = val; 
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,0,grid); 
        if(ans<0) return 0;
        // if(dp[n-1][n-1][][]==-1) return 0;
       return  ans;
    }
};
