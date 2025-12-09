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
    vector<int> ans;
    int dfs(int n){
      int c=0;
      for(auto i: grp[n]){
        c+=dfs(i)+1;
      }
      return ans[n]=c;
      
    }

void solve() {
    // Your solution code here
   int n;cin>>n;
   ans.resize(n+1);
    grp.resize(n+1);
    for(int i=2;i<=n;i++){
      int a;cin>>a;
      grp[a].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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