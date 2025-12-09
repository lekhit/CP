#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

#define int  long long

const int INF=1e18+7;

vector<int> dji(int start, int n, vector<vector<pair<int,int>>> &grp){
    priority_queue<pair<int,int>> pq;
    vector<int> dist(n+1, INF);
    dist[start]=0;
    pq.emplace(0, start);
    while(!pq.empty()){
        auto [weight, u]=(pq.top());pq.pop();
        if(-weight > dist[u]) continue; // -weight because we add negative weights
        for(auto [v, w]: grp[u]){
            if(dist[u]+w >= dist[v]) continue;
            dist[v]=dist[u]+w;
            pq.emplace(-dist[v], v);
        }
    }
    return dist;
}

void solve() {
    // Your solution code here
   int n,m;cin>>n>>m;
   vector<vector<pair<int,int>>> grp(n+1), agrp(n+1);
   vector<tuple<int,int,int>> edges;
   for(int i=0; i<m;i++){
    int u,v,w;cin>>u>>v>>w;
    edges.emplace_back(u,v,w);
    grp[u].emplace_back(v,w);
    agrp[v].emplace_back(u, w);
   }
   auto fromStartNodeDist=dji(1, n, grp);
   auto fromEndNodeDist=dji(n, n, agrp);
   int result=INF;

   for(auto [u, v, w]: edges){
    int cost=fromStartNodeDist[u]+(w/2)+fromEndNodeDist[v];
    result=min(cost, result);
   }

   cout<<result;

}

int32_t main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("i.txt", "r", stdin);
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