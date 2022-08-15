//Longest Subsequence having difference atmost K between adjacent element.
// -> try to find all the subsequence of given string 
//-> what is the range of each character of string.   
//upper bound-> max(25,curr+k)
//lower bound-> min(0,curr-k)



//Subsequence me previous kaun sa character jo mere sath chipak sakta hai whi character jisse mere difference <=k rhe Bas Simple hai.
for(int i=0;i<S.length();i++){
  
  int curr = S[i]-'a';
  int ub = max(25,curr+k);
  int lb = min(0,curr-k);
  for(int j=lb; j<=ub; j++){
    dp[i]=max(dp[i], maxLen[j]+1);
  }
  maxLen[curr] = max(dp[i], maxLen[curr]);
 
}
//Max of Dp is the final Answer.
