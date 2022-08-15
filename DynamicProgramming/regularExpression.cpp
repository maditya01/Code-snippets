class Solution {
public:
    
    

 //Pattern * inputString Matrix banani hai 
 //Now Transition is Important.
 //   
 //ith character * hai to    
//.*-> ..*    
    
    bool isMatch(string s, string p) {

        int n=s.size();
        
        int m=p.size();
        
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        
        dp[0][0]=1;
        
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*'){
                dp[i][0]= dp[i-2][0];
                // cout<<dp[i][0]<<endl;
            }
        }
        
        for(int i=1;i<=m;i++){         
            for(int j=1;j<=n;j++){
               if(p[i-1]=='.' or (s[j-1]==p[i-1])){
                  dp[i][j] = dp[i-1][j-1];//diagonal dekhna hai.
              }
             else if(p[i-1]=='*'){                 
                    bool ch1=false;                   
                    if(i-2>=0) ch1 = dp[i-2][j];                    
                    if( i-2>=0 and (p[i-2]==s[j-1] or p[i-2]=='.') ) {
                        ch1= ch1 or dp[i][j-1];
                        // cout<<ch1<<" "<<endl;
                    }
                    dp[i][j]=ch1;
              }
             else if(p[i-1] != s[j-1]){
                  dp[i][j]=0;
              }              
                // cout<<dp[i][j]<<" ";                
            }
            // cout<<endl;
        }
        return dp[m][n];
        
    }
};
