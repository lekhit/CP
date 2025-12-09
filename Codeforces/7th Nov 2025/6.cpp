#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define int long long
#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

void solve() {
    // Your solution code here
   int n,m,q;cin>>n>>m>>q;
   vector<int> a(n),b(m);
   for(auto &i: a)cin>>i;
   for(auto &i: b)cin>>i;
   vector<int> r,c;
   int curr_sum=0;
   for(int i: a)
   {int ans=0;
    for(int j: b){
      ans+=i*j;
   }
   curr_sum+=ans;
   r.push_back(ans);
  }
  for(int i:b){
    int ans=0;
    for(int j:a){
      ans+=i*j;
    }
    c.push_back(ans);
  }
  set<pair<int,int>> cc;
  for(int i=0;i<n;i++){
    cc.insert({c[i],i});
  }
  while(q--){
    int x;cin>>x;
    int toFind=curr_sum-x;
    for(auto i: r){

    }
  }
}

int32_t main() {
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