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
   int n;cin>>n;vector<int> v(n), ans(n, 0);
   for(auto &i:v)cin>>i;
   int m=v[0];ans[0]=1;
   for(int i=0;i<n;i++){
    if(v[i]<m) ans[i]=1;
    m=min(m, v[i]);
   }
   m=v[n-1];ans[n-1]=1;
   for(int i=n-1; i>=0; i--){
    if(v[i]>m) ans[i]=1;
    m=max(m, v[i]);
   }
   for(auto i: ans) cout<<i;

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