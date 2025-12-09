#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = true;
#endif
typedef int long long;

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

vector<vector<pair<int,int>>> makeAdj(int n, vector<int> roads_from, vector<int> roads_to, vector<int> roads_weight){
    vector<vector<pair<int,int>>> arr(n);
    for(int i=0;i<roads_weight.size();i++){
        arr[roads_from[i]].emplace_back(roads_to[i], roads_weight[i]);
    }
    return arr;
}

vector<vector<int>> makeAdj2(int n, vector<int> roads_from, vector<int> roads_to, vector<int> roads_weight){
   int INF=1e9+7;
    vector<vector<int>> adj(n+1, vector<int>(n+1, INF));
    for(int i=0;i<roads_from.size();i++){
        adj[roads_from[i]][roads_to[i]]=roads_weight[i];
    }
    return adj;
}

vector<int> findMin(int road_nodes, int m, vector<int> roads_from, vector<int> roads_to, vector<int> roads_weight){
int INF=1e9+7;
int n=road_nodes;
    auto adj=makeAdj2(road_nodes, roads_from, roads_to, roads_weight);

vector<vector<int>> distance(road_nodes+1, vector<int>(road_nodes+1, INF));
for(int i=0;i<=road_nodes;i++){
    for(int j=1;j<=road_nodes;j++){
        if(i==j) distance[i][j]=0;
        else if(adj[i][j]) distance[i][j]=adj[i][j];
        else distance[i][j]=INF;
    }
}

for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            distance[i][j]=min(distance[i][j], distance[i][k]+distance[k][j]);
        }
    }
}

// for(auto i: distance) {for(auto j: i) cout<<j<<" "; cout<<endl;}

vector<int> ans(n+1, INF);

for(int node=1;node<=n;node++){
    ans[node]=adj[node][node]; // for self loops
}
for(int node=1;node<=n;node++){
    for(int from_node=1;from_node<=n;from_node++){
        if(node==from_node) continue;
        ans[node]=min(ans[node], adj[from_node][node]+distance[node][from_node]);
        // cout<<ans[node];
    }
}

for(int i=1;i<=n;i++){
    if(ans[i]==INF) ans[i]=0;
    cout<<ans[i]<<" "; // for debugging
}
return ans;
}
void solve() {
    // Your solution code here
   int n, m;cin>>n>>m;
   vector<int> from, to, weight;
   for(int i=0;i<m;i++){int a;cin>>a; from.push_back(a);}
   for(int i=0;i<m;i++){int a;cin>>a; to.push_back(a);}
   for(int i=0;i<m;i++){int a;cin>>a; weight.push_back(a);}
//    for(int i=0;i<m;i++){
//     int a,b,w;
//     cin>>a>>b>>w;
//     from.push_back(a);to.push_back(b);weight.push_back(w);
//    }
   findMin(n, m, from, to, weight);
}

int main() {
    fastio;
      freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    
    // File I/O (local only)
    if(LOCAL_ENV) {
      
    }

int t=1;
//cin>>t;
    while(t--) {
        solve();
    }

    
    return 0;
}