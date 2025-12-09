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
   int N,m;cin>>N>>m;
   int p=0, pv=0;
   int ans=0;
   for(int i=0;i<N;i++){
    int n,nv;cin>>n>>nv;
    ans+=n-p;
    if(!(((p&1)==(n&1) && pv==nv) || (p&1)!=(n&1) && pv!=nv)){
      ans-=1;
    }
    p=n;pv=nv;
   }
   ans+=(m-p);
   cout<<ans<<endl;
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
    }

    
    return 0;
}