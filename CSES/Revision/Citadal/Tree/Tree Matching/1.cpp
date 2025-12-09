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

vector<set<int>> grp;
vector<int> vis;
vector<pair<int,int>> dp;

pair<int,int> dfs(int n, int p){
  if(vis[n]) return dp[n];
  vis[n]=1;
  pair<int,int> ans={0,0};
  auto &[NisFree, NisPaired]=ans;
  int totalValWhenIisPaired=0, totalValWhenIisFreeAndReadyToPairWithN=0;
  for(auto i: grp[n]){
    if(i==p) continue;
    auto [IisFree, IisPaired]= dfs(i, n);
    totalValWhenIisPaired+=IisPaired;
    totalValWhenIisFreeAndReadyToPairWithN+=IisFree;
  }
  NisFree=totalValWhenIisPaired; // also needs attentation when I move to the case of double loops
  for(auto i: grp[n]){
    if(i==p) continue;
    auto [IisFree, IisPaired]= dfs(i, n);
    // if this dos't work then need to go for double loop where I need to keep on rechecking all the pairs
    NisPaired=max(IisFree+1+(totalValWhenIisPaired-IisPaired), NisPaired);
  }
  return dp[n]=ans;
}

void solve() {
    // Your solution code here
   int n;cin>>n;
   grp.resize(n+1);
   vis.assign(n+1, 0);
   dp.resize(n+1);
   for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    grp[a].insert(b);
    grp[b].insert(a);
   }
   auto [a1, a2]=dfs(1, -1);
   cout<<max(a1,a2);
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