//Take Care Which Variable,data structure i am using  
void make(int v){
     parent[v]=v;
     sz[v]=1;
 }   

 int find(int v){
     if(v==parent[v]) return v;
     return parent[v]=find(parent[v]);
 }
    
void Union(int u,int v){
u=find(u);
v=find(v);
    if(u!=v){
        if(sz[u]<sz[v]) swap(u,v);
        parent[v]=u;
        sz[u]+=sz[v];
    }
}    
    
  
