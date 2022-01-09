//Usual Meanings of all DS
bool checkDirectedCycle(int source){
global_vis[source]=true;
local_vis[source]=true;
 for(auto v:adj[u]){
 if(!global_vis[v]){   
   if(checkDirectedCycle(v)){
       return true;
   }
 }
 else if(local_vis[v]==true) return true;
 }
  //you have finised subtree[adjacent] of vertex u
  local_vis[u]=false;
  return false;
}
