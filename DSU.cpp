//Take Care Which Variable,data structure i am using  
void make(int v){
     parent[v]=v;
     sz[v]=1;
 }   

 int find(int v){
     if(v==parent[v]) return v;
      //Path Compression
     return parent[v]=find(parent[v]);
 }
    
void Union(int u,int v){
u=find(u);
v=find(v);
    if(u!=v){
         //Connection of big component with small component
         //u as big Component v as small Component
        if(sz[u]<sz[v]) swap(u,v);
        parent[v]=u;
        sz[u]+=sz[v];
    }
}    
    
  
