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

void solve() {
    // Your solution code here
   int n,m;cin>>n>>m;
   int INF=1e9+7;
   vector<vector<int>> grp(n+1);
   for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    grp[a].push_back(b);
    grp[b].push_back(a);
   }
   queue<int> q;
   vector<int> parent(n+1, -1), vis(n+1,INF);
   q.push(1);
   while(!q.empty()){
    auto node=q.front();
    q.pop();
    if(node==n) break;
    for(auto i: grp[node]){
        if(vis[i]==INF){
            q.push(i);
            parent[i]=node;
            vis[i]=vis[node]+1;
        }
    }
   }
   if(vis[n]==INF)cout<<"IMPOSSIBLE";
   else{
    int node=n;
    vector<int> ans;
    while(node!=1){
        ans.push_back(node);
        node=parent[node];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<'\n';
    for(auto i: ans) cout<<i<<" ";
   }
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