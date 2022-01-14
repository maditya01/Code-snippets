//Remeber which data structure i am using dis-> distance array of size n or n+1 
//ms-> multiset for getting minimum distance, pair of {distance,vertex}-> first distance second is vertex 
//edges-> graph representation using list
//Take a graph and visualise this algo at every step.
void shortestPath(int source){
     dis[source]=0;
     ms.insert({0,source});
     while(!ms.empty()){
         int d=ms.begin()->first;//Try to Get Minimum Distance
         int u=ms.begin()->second;
         ms.erase(ms.begin());
          if(d>dis[u]) continue;//if d is greater that dis[u] 
         for(auto v:edges[u]){
             if(dis[v.first]> dis[u]+v.second){
                 dis[v.first]=dis[u]+v.second;
                 cout<<dis[v.first]<<endl;
                 ms.insert({dis[v.first],v.first});
             }
         }
     }
 }
