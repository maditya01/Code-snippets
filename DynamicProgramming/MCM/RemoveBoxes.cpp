//you have array of different colors 
// Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.
//Means Continuous K [same colors] ko chosse karo.

you start from by taking Complete Range-> (0....n-1)
//Very Logical But Very Good Question.

 class Solution {
public:
int dp[101][101][101];    
int removeBoxes2(int i, int j, int k,vector<int>&boxes) {

	if (i > j) return 0;

if(dp[i][j][k]!=-1) return dp[i][j][k];
// [i.....j]

	int i0 = i, k0 = k;
// one choice i ko destroy kar do.
//i+1,i+2,i+3 bhee i ke equcal hain to sabko ak sath destroy karo na.
	while (i + 1 <= j and boxes[i + 1] == boxes[i]) {
		i++;
		k++;
	}

	int res = 0;
	res = max(res, (k + 1) * (k + 1) + removeBoxes2(i + 1, j, 0,boxes));

// second choice hai i ko kisi same color as i ke sath combine karke destroy karo


	for (int m = i + 1; m <= j; m++) {
		if (boxes[i] == boxes[m]) {
			res = max(res, removeBoxes2(i + 1, m - 1, 0,boxes) + removeBoxes2(m, j, k + 1,boxes));
		}
	}

	return dp[i0][j][k0] = res;


}
    int removeBoxes(vector<int>& boxes) {
     memset(dp,-1,sizeof(dp));
    int n=boxes.size();
    return removeBoxes2(0,n-1,0,boxes);
        
    }
};
