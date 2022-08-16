class Solution {
public:
    bool isMatch(string s, string p) {
        //p*s I am assuming. ak baar p*s table bana kar dekho apne
        //aap sare concept clear ho jayega.
    Notes:
        1.Once * came 
        int n=p.size();
        int m=s.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        //0th character as space .we are assuming.
       dp[0][0]=1;//base case 0th character of p is matching 0th character of  s.
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(p[i-1]=='*'){
                dp[i][0]= dp[i-1][0];
            }
        }
        for(int i=1;i<=n;i++){
            if(dp[i][0]==true){
                flag=true;
            }
            for(int j=1;j<=m;j++){
                if(flag==true){
                    dp[i][j]=1;
                    continue;
                }
                if(p[i-1]=='*'){
                    dp[i][j]=  dp[i-1][j];
                    if(dp[i][j]==1){
                        flag= true;
                    }
                    
                }else if(p[i-1]=='?' or s[j-1]==p[i-1]){                    
                    dp[i][j]= dp[i-1][j-1];
                }
                else if(p[i-1]!=s[j-1]){
                    dp[i][j]=false;
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
            flag=false;            
        }
        return dp[n][m];
    }
};
