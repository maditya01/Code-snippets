#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[int(1e6)];
//We will use dijkastra algorithm
vector<vector<int>> dp;
void Dijkastra(int u,int k){
	multiset<vector<int>> ms;
	ms.insert({0,0,1});
	dp[u][0] = 0;
  //dp[i][j] -> Min cost to reach vertex i using j coupons.
	while(ms.size()>0){
		vector<int> v = *ms.begin();
		int d = v[0];
		int kd = v[1];
		int ver = v[2];
		
		ms.erase(ms.begin());
		
		for(auto i: adj[ver]){
			int child = i.first;
			int we =  i.second;
			//2 choices.
			// Without using Offer
			if(dp[child][kd]>d+we){
				dp[child][kd] = d+we;
				ms.insert({dp[child][kd],kd,child});
			}
			//With using Offer
			if(kd+1<=k and dp[child][kd+1]>d){
				dp[child][kd+1] = d;
				ms.insert({dp[child][kd+1],kd+1,child});
			}
		}
	}
}

int main() {
	int V,E,k;
	cin>>V>>E>>k;

	dp.resize(V+1,vector<int>(k+1,int(1e8)));

	for(int i=0;i<E;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w}); 
	}
	Dijkastra(1,k);
	for(int i=1;i<=V;i++){
		int mn = INT_MAX;
		for(int j=0;j<=k;j++){
			mn = min(mn,dp[i][j]);
		}
		cout<<mn<<" ";
	}

}
