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
vector<vector<int>> vis;

void dfs(int x, int y){
    if(grp[x][y]==0) return;
    if(vis[x][y])return;
    vis[x][y]=1;
    vector<pair<int,int>> pr={{x+1, y}, {x-1, y}, {x, y+1}, {x, y-1}};
    for(auto [a,b]: pr){
        if(a>=0 && b>=0 && a<grp.size() && b<grp[0].size()){
            dfs(a,b);
        }
    }
}

void solve() {
    // Your solution code here
   int n,m;cin>>n>>m;
   grp.assign(n,vector<int>(m));
   vis=grp;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        char ch;cin>>ch;
        if(ch=='#')grp[i][j]=0;
        else grp[i][j]=1;
    }
   }
   int count=0;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(vis[i][j]) continue;
        else{
            if(grp[i][j])
            {count++;
            dfs(i,j);}
        }
    }
   }
   cout<<count;
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