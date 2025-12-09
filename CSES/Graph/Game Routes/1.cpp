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
vector<int> dp;
vector<int> vis;
const int UNVISITED=-1,VISITED=1,MOD=1e9+7;
int dfs(int n){
    if(vis[n]==VISITED) return dp[n];
    for(auto i: grp[n]){
        (dp[n]+=dfs(i))%=MOD;
    }
    vis[n]=VISITED;
    return dp[n];
}
void solve() {
    // Your solution code here
   int n,m;cin>>n>>m;
    grp.resize(n+1);
    dp.assign(n+1, 0);
    vis.assign(n+1, UNVISITED);
    dp[1]=1;
   for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    grp[b].push_back(a);
   }
   for(auto i:grp) {for(auto j:i) cerr<<j<<" "; cerr<<"\n";} 
   cout<<dfs(n);
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