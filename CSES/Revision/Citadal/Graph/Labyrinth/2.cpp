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
   vector<vector<char>> grp(n, vector<char>(m));
   vector<vector<int>> vis(n, vector<int>(m,0));
   pair<int,int> start,end;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grp[i][j];
        if(grp[i][j]=='A') start={i,j};
        if(grp[i][j]=='B') end={i,j};
    }
   }
   vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m));

   queue<pair<int,int>> q;
   q.push(start);
   while(!q.empty()){
    auto node=q.front();
    if(node==end) break;
    q.pop();
    
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