//How Many Different ways 
//n people 40 types of different hats.
//array given which tells which hat is prefered by which person.
// Return the number of ways that the n people wear different hats to each other.

//2 things to remember
// 1.mask kiska banega 
// 2.Recursion me as an argument kya pass hoga
//For example in this question mask me peoples ke information hai
//argument me hatNumber pass hoga

typedef long long ll;
class Solution {
public:
int mod=int(1e9)+7;
bool own[11][41];    
int n;
ll dp[41][(1<<11)-1];
int solve(int hat,int mask){ 
    // cout<<mask<<endl;
 if(mask==0) return 1;
 if(hat>40) return 0;
 if(dp[hat][mask]!=-1) return dp[hat][mask];
     ll ans=0;
     for(int j=0;j<n;j++){       
         if(own[j][hat] == true and mask & (1 << j) ){
           ans = (ans*1LL + solve(hat+1, mask ^ (1 << j))*1LL)%mod;  
         } 
     }
     ans = (ans*1LL + solve(hat+1,mask)*1LL)%mod;
     return dp[hat][mask]= (ans%mod);
}
    
int numberWays(vector<vector<int>>& hats) {
      n = hats.size();
    memset(dp,-1,sizeof(dp));
        for(int i=0;i<hats.size();i++){
            for(auto j:hats[i]){
               own[i][j]=true;
            }
        }
    return solve(1,(1<<n)-1);
    }
};
