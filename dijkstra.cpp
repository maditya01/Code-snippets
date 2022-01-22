//Remeber which data structure i am using dis-> distance array of size n or n+1 
//you can use min priority_queue inseated of multiset
//ms-> multiset for getting minimum distance, pair of {distance,vertex}-> first distance second is vertex 
//edges-> graph representation using list
//Take a graph and visualise this algo at every step.
void shortestPath(int source){
     dis[source]=0;//source has distance 0 from source itself
     ms.insert({0,source});//insert that thing in ms
     while(!ms.empty()){
         int d=ms.begin()->first;//Try to get a vertex which has a Minimum Distance-> GREEDY APPROACH
         int u=ms.begin()->second;//vertex associated with that distance
         ms.erase(ms.begin());
          if(d>dis[u]) continue;//if d is greater that dis[u] 
         for(auto v:edges[u]){
             if(dis[v.first]> dis[u]+v.second){
                 dis[v.first]=dis[u]+v.second;
                 ms.insert({dis[v.first],v.first});
             }
         }
     }
 }

//Now you have a distance array which has distance from source to ith vertex ->
// graph 1 based hai ya 0 based  usi ke according distance array hai