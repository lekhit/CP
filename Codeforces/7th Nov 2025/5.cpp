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
   int k, l1, r1, l2, r2;cin>>k>>l1>>r1>>l2>>r2;
   int ans=0;
   for(int p=1; p<=r2; p*=k){
    if(l2/p > r1) continue;
    if(r2/p < l1) continue;
    int left=max(l1, (l2+p-1)/p);
    int right=min(r1, r2/p);
    ans+=(right-left)+1;
   }
   cout<<ans;
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
        cout<<"\n";
    }

    
    return 0;
}