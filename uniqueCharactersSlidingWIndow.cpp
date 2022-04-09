//i have to tell what is the maxLength of a window which has uniqueChar number of unique Characters.

int solve(string s,int uniqueChar){
  
vector<int> mp(256,0);
int b=0,e=0,ans=0;
int cnt=0;//Counting the unique Characters
  
while(e<s.length()){
 mp[int(s[e])]++;
 if(mp[int(s[e])]==1){
     cnt++;
 }
  
 //Invalid substring
 while(cnt>uniqueChar){
    mp[int(s[b])]--;
    if(mp[int(s[b])]==0){
        cnt--;
    }
    b++;
 }
 if(cnt==uniqueChar){
     ans=max(ans,e-b+1);
 }
 e++;
}
return ans;
}
