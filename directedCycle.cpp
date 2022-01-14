//Usual Meanings of all DS
bool checkDirectedCycle(int u){
global_vis[u]=true;
local_vis[u]=true;
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
