int V, E;
vector<int>adj[100005];
bool vis[100005];
vector<int> parent;
vector<int>dis_time; //koi vertex kis time par discover hua hai
vector<int>low_time; //koi vertex ke adjacent me jo sabse

// minimum  discovered time  hoga ye isi ka hoga
//low_time of a vertex is ki uske adjacency list me jo bhee minimum
//{discovered_time } or {low_time } hoga wo ho jayega khud se compare karke

int Time = 1;
vector<int>art;

//Mujhe u vertex ko check karna hai ki articulation
//point hai ki nhi mai DFS(adjacent of u that is v,u) dekhunga
//agar u vertex ke descendent me koi ak aisa vertex hai jo ki
// u vertex ke ancestor ke sath juda hai to u articulation point nhi ho sakta.
//other wise u ak articulation point hoga


void dfs(int u, int par) {
	int child_count = 0;//count of child of a vertex.
	vis[u] = true;//vertex u ko visit kar liye hai
	parent[u] = par;//
	dis_time[u] = low_time[u] = Time++; //abhee vertex u ka dis,low time same hai
	for (auto v : adj[u]) {
		//jab bhee adjacent vertex that is (v) not visited hai to vo if wale part me jayega
		//visited hai to vo else wale part me jayega.
		if (v == par) {
			continue;//jaha se aya tha just usi ke pass phir se u-v hokar v-u jane ki koshish
		}
		if (!vis[v]) {
			child_count++;
			dfs(v, u);
			//1-2-3-4   last dfs(4,3) call
			//// low[v] might be an ancestor of u
			low_time[u] = min(low_time[v], low_time[u]);//yha dono ke low time
			//se compare karenge. ? why.
			if (parent[u] == -1 && child_count > 1) {
				cout << u << endl;
				art[u] = 1;//root vertex ho jayega.
			}
			//back track hokar jo last call hue thee
			//whi same to same (v,u) ho jayenge.
			//same dfs at the time of backtrack dfs(v,u)
			if (dis_time[u] <= low_time[v] and parent[u] != -1) {
				cout << u << endl;
				art[u] = true;// iska matlab hai u ke adjacent v ka low time change nhi
				//hua hai low time kab change hoga jab v jo hai to u ke ancestor ke sath
				//juda hoga jab tum minimum loge to us ancestor ka discovery time ayega
				//jo ki u ke discovery time se kam hoga kyoki wo u ka ancestor hai.
				//to jab ye wali condition satisfy nhi hogi kyoki
				//vertex v ka low  vertex u ke time discovery time se kam ho gya.
			}

		}
		//YHA PAR CALL KAB AYEGI
		//last vertex hoga tumhare graph me matlab jiski adjacency list me ya to
		//sare visited vertex hoge ya to bas iska parent hoga.
		//us vertex ka lowtime update kar do.//kaise iska jo child hai
		//uske discovery time se compare karke upna low time declare karo.
		//phir dfs call me wapas jaoge
		else {
      //if v was already discovered means that we found an ancestor
			//yha tabhee ayega jab phle se visited
			//vertex ko dekhne ki koshish karega
			//yha u ,v me confusion mat rkho
			//v humesha child hoga u humesha wo hoga jiski
			//adj list chal rhi hogi.
			low_time[u] = min(low_time[u], dis_time[v]);//
			// finds the ancestor with the least discovery time
		}
	}
}
