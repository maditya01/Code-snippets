//Maximum Number of points from matrix 
//From each row choose only one element
//Net value is subtracted by abs diff of column of previous row.

//->Bottom Up DP Lagega.

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        
        int m = points.size();
        int n = points[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,0));//just for sake of 
        vector<long long int> prev(n);//store the value of previous row.
        for(int j=0;j<n;j++) prev[j]=points[0][j];
        long long int t=0;
        for(int i=1;i<m;i++){
            vector<long long int> left(n);//store the value for 0...i
            vector<long long int> right(n);//store the value for i...n-1
            vector<long long int> curr(n);
            left[0] = prev[0];
            right[n-1]=prev[n-1];
            for(int j=1;j<n;j++){
                left[j] = max(left[j-1]-1, prev[j]); //each time left[] se -1 kar rhe ho so overall reflect kar jayega.
            }
            for(int j=n-2;j>=0;j--){
                right[j] = max(right[j+1]-1, prev[j]); // each time right[] se -1 kar rhe ho so overall reflect kar jayega.
            }             
            for(int j=0;j<n;j++){
                curr[j]= points[i][j] + max(left[j],right[j]);
            }
             prev=curr;
            }
        long long int ans =0;
        for(int i=0;i<n;i++){
            ans= max(ans,prev[i]);
        }
        return ans;
    }
};












