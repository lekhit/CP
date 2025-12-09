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

vector<vector<int>> grp;
vector<int> vis;

void dfs(int n, int p){
    if(vis[n]) return;
    vis[n]=1;
    for(auto i: grp[n]){
        if(i==p) continue;
        dfs(i, n);
    }
}

void solve() {
    // Your solution code here
   int n,m;cin>>n>>m;
   grp.resize(n+1);
   vis.assign(n+1,0);
   for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    grp[a].push_back(b);
    grp[b].push_back(a);
   }
   vector<int> ans;
   for(int i=1;i<=n;i++){
    if(!vis[i]){
        ans.push_back(i);
        dfs(i, -1);
    }
   }
   cout<<(ans.size()-1)<<"\n";
   for(int i=1;i<ans.size();i++){
    cout<<ans[0]<<" "<<ans[i]<<"\n";
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