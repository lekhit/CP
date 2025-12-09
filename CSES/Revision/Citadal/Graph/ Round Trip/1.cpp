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
vector<int> vis, ans;

void dfs(int n, int p){
    if(vis[n]){
        ans.push_back(n);
        return;
    }
    vis[n]=1;
    for(auto i: grp[n]){
        if(i==p) continue;
        dfs(i, n);
        if(ans.size()>0) break; // backtracking started
    }
    if(ans.size()>0){
         if(ans.size()>1 && ans.back()==ans.front()){
            return;
        }
        ans.push_back(n);
    }
}

void solve() {
    // Your solution code here
   int n,m;cin>>n>>m;
   grp.resize(n+1);
   vis.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i] && ans.size()==0)
            dfs(i, -1);
    if(ans.size()==0){
        cout<<"IMPOSSIBLE";
    }else{
        cout<<(ans.size())<<'\n';
        for(auto i: ans){
            cout<<i<<" ";
        }
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