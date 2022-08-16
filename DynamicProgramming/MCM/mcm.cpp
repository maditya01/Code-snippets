//[.  .  .  .  .]
//by taking differnt Number of elements [. .]*[. . .] 
//[.]*[. . . .]
//[. . .]*[. .]
 //Here in Matrix Chain Multiplication we are doing same thing we try to multiply matrix in different manners.
//Cost of 2  Matrix to multiply is  i*j j*k  => i*j*k.

int matrixMultiplication(vector<int> &arr, int N){
   
    int n = N;
    
    vector<vector<int>> dp(n,vector<int>(n,int(1e8)));
 
 for(int gap=0;gap<n-1;gap++){
         int i=0, j=gap;
            while(j<n-1){
                if(gap == 0){
                    dp[i][j] = 0;
                }else if(gap == 1){
                    dp[i][j] = arr[i]*arr[j]*arr[j+1];
                }else{
                    int ans = INT_MAX;
                    if(dp[i][j]=int(1e8)) dp[i][j]=0;
                    for(int k=i; k<j; k++){
                        ans= min(ans,dp[i][k] + dp[k+1][j] + (arr[(i)])*arr[(k+1)]*arr[(j+1)]);
                    }
                    dp[i][j]=ans;
                }
                i++;
                j++;
            }
        }
    
    return dp[0][n-2];
}

