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
   int MOD=1e9+7;
   int sum=(n*(n+1))>>1;
   if(sum&1) {
    cout<<0;return;
   }
   sum>>=1;
   vector<int> cur(sum+1),pre(sum+1);
   cur[0]=1;
   for(int i=1;i<=n;i++){
    pre=cur;
    for(int j=1;j<=sum;j++){
        if(j-i >=0){
            (cur[j]+=pre[j-i])%=MOD;
        }
    }
   }
   int inv2 = 500000004;
  cout << (cur[sum] * inv2) % MOD;
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