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

#define int long long
const int INF=1e18+7;

vector<priority_queue<int>> dji(int n, vector<vector<pair<int,int>>> grp){
    priority_queue<int> st;
    for(int i=0;i<10;i++) st.emplace(INF);
    vector<priority_queue<int>> dist(n+1, st);
    // max val till now and counter
    vector<pair<int,int>> dist2(n+1, {INF, 0});
    vector<int> counter(n+1, 0);
    // dist[1].emplace(0);
    priority_queue<pair<int,int>> pq;
    pq.emplace(0, 1);
    while(!pq.empty()){
        auto [curDist, u]=pq.top(); pq.pop(); curDist*=-1;
        if(!dist[u].empty() && -curDist >= dist[u].top()) continue;
        for(auto [v, w]:grp[u]){
            auto temp=curDist+w;
            if(!dist[v].empty() && temp >= dist[v].top()) continue;
            dist[v].emplace(temp);
            if(dist[v].size()>10) dist[v].pop();
            pq.emplace(-(temp), v);
        }
    }
    return dist;
}

void solve() {
    // Your solution code here
   int n,m,k;
   cin>>n>>m>>k;
   vector<vector<pair<int,int>>> grp(n+1);
   for(int i=0;i<m;i++)
   {
    int u,v,w;
    cin>>u>>v>>w;
    grp[u].push_back({v,w});
   }
   auto rs=dji(n, grp);
   vector<int> results;
   while(!rs[n].empty()){results.emplace_back(rs[n].top());rs[n].pop();}
   reverse(results.begin(),results.end());
   for(int i=0;i<k;i++) cout<<results[i]<<" ";

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