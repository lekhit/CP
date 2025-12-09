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
   int n;cin>>n;
   vector<int> v(n),missed, ans;for(auto &i: v)cin>>i;
   set<int> s;
   s.insert(v.begin(), v.end());
   for(int i=1;i<=n;i++){
    if(!s.count(i)){
      missed.emplace_back(i);
    }
   }
   s.clear();
   for(int i=0,j=0;i<n;i++){
    if(s.count(v[i])){
      ans.push_back(missed[j]);j++;
    }else{
      ans.push_back(v[i]);
      s.insert(v[i]);
    }
   }
   for(auto i:ans) cout<<i<<" ";
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
cin>>t;
    while(t--) {
        solve();
        cout<<'\n';
    }

    
    return 0;
}