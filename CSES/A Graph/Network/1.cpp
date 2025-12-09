#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

// Custom hash for pair<int,int>
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

void solve() {
    // Your solution code here
   int n,m,k;cin>>n>>m>>k;
   vector<pair<int,int>> edges;
   vector<pair<int,int>> brokenConnections;
   vector<int> graph[n+1];
   while(m--){
    int a,b;cin>>a>>b;
    edges.push_back({a,b});
   }
   while(k--){
    int a,b;cin>>a>>b;
    brokenConnections.push_back({a,b});
   }
   unordered_set<pair<int,int>, pair_hash> brokenConSet;
   for(auto [i,j]:brokenConnections){
        brokenConSet.insert({i,j});
        brokenConSet.insert({j,i});
   }
   //Make graph without broken connections

   for(auto edge: edges){
    auto [i,j]=edge;
    if(brokenConSet.count(edge)==0){
        // unbroken connection only
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
   }

// implement DSU
   vector<int> parent(n+1,0);
   vector<int> rank(n+1,0); // represents number of components that connect to the i'th node; Ideally we want maxium nodes connects to single root, this helps with lesser jumps to find root;

   function<int(int)> findRoot= [&](int i){
    return parent[i]==i ? i: parent[i]=findRoot(parent[i]);// path compression
   };
   function<void(int,int)> merge=[&](int i, int j){
    int a=findRoot(i),b=findRoot(j); // this could have been used without rank
    if(rank[a]<rank[b]){
        swap(a,b);
    }
    parent[b]=a;
    if(rank[a]==rank[b]) rank[a]++;//because now b has parent as node a
   };
   //initiate dsu
   for(int i=1;i<=n;i++){
    parent[i]=i;
   }
   
//DFS
   vector<int> visited(n+1, 0);
   function<int(int)> dfs = [&](int index){
    if(visited[index]) return 0;
    visited[index]=1;
    for(auto i: graph[index]){
        dfs(i);
        merge(index, i);
    }
    return 1;
   };

   //count present islands
   int count=0;
   for(int i=1;i<=n;i++){
    count+=dfs(i);
   }

   // reconnecting the connections in reverse order
   reverse(brokenConnections.begin(),brokenConnections.end()); // reversed so that last broken will be first connected; Note: answer will also be in reverse order
   vector<int> ans;
   for(auto [i,j]: brokenConnections){
    int a=findRoot(i);
    int b=findRoot(j);
    ans.push_back(count);
    if(a!=b){
        // not connected
        merge(i,j);
        count--;
    }
    
   }
   reverse(ans.begin(),ans.end());
   for(auto i:ans)
   cout<<i<<" ";


}

int main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

int t=1;
//cin>>t;
    while(t--) {
        solve();
    }

    
    return 0;
}