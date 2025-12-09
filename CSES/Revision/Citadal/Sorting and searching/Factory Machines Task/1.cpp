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

    int n,x;cin>>n>>x;
    vector<int> v(n);for(auto &i:v)cin>>i;
    auto isPossible=[&](int target){
      int c=0;
      for(auto i: v){
        c+=target/i;
        if(c>=x) return true;
      }
      return c>=x;
    };
    int lo=0, hi=1e18+7;
    while(lo<=hi){
      int mid=lo+(hi-lo)/2;
      if(isPossible(mid)){
        hi=mid-1;
      }else{
        lo=mid+1;
      }
    }
    cout<<lo;
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