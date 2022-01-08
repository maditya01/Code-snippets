//Remeber which data structure i am using dis-> distance array of size n or n+1 
//ms-> multiset for getting minimum distance, pair of {distance,vertex}-> first distance second is vertex 
//edges-> graph representation using list
void shortestPath(int source){
     dis[source]=0;
     ms.insert({0,source});
     while(!ms.empty()){
         int u=ms.begin()->second;
          int d=ms.begin()->first;
         ms.erase(ms.begin());
          if(d>dis[u]) continue;
         for(auto v:edges[u]){
             if(dis[v.first]> dis[u]+v.second){
                 dis[v.first]=dis[u]+v.second;
                 cout<<dis[v.first]<<endl;
                 ms.insert({dis[v.first],v.first});
             }
         }
     }
 }
