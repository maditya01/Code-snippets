//Can we Devide Given set of vertices in 2 sets such that for all edges one end in first set and another end in second set.


vector<int> val;//Take val array Flip value between consective vertices.
vector<bool> vis;//Visited array because Graph can be cycle
 bool CheckBipartite(int i,vector<vector<int>>& graph,int p){
    vis[i]=true;
    for(auto j: graph[i]){
      if(val[i]==val[j]) return false;//This is the First Line before continue statement.
      if(j==p or vis[j]) continue;
       val[j] = !val[i];
      if(!CheckBipartite(j,graph,i)) return false;      
    }
    return true;   
}
