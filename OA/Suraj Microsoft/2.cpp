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

void dfs(int n, int p,int c, vector<int> &cluster, vector<int> &vis, vector<vector<int>> &grp){
  if(vis[n]) return;
  vis[n]=1;
  cluster[n]=c;
  for(auto i: grp[n]){
    if(i!=p){
      dfs(i, n, c, cluster, vis, grp);
    }
  }
}

vector<int> getCluster(int n, vector<int> serverProp){
  n=serverProp.size();
vector<vector<int>> grp(n+2);
map<int,int> compress, decompress;
int c=1;
for(auto i: serverProp){
  if(!compress.count(i)){
    compress[i]=c;
    c++;
  }
}
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j){
        if(gcd(serverProp[i], serverProp[j])>1){
          grp[compress[serverProp[i]]].push_back(compress[serverProp[j]]);
          grp[compress[serverProp[j]]].push_back(compress[serverProp[i]]);
        }
      }
    }
  }
  vector<int> cluster(n+1,0), vis(n+1, 0);
  int clusterIndex=1;
  for(int i=1;i<=n;i++){
    if(!vis[i]){
    dfs(i, -1, clusterIndex, cluster, vis, grp);
    clusterIndex++;
  }}
  vector<int> ans;
  for(auto i: serverProp){
    ans.push_back(cluster[compress[i]]);
  }
  return ans;
}

void solve() {
    // Your solution code here
    int n;cin>>n;
    vector<int> v(n); for(auto &i: v)cin>>i;
   auto ans=getCluster(n, v);
   for(auto i: ans) cout<<i<<" ";
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