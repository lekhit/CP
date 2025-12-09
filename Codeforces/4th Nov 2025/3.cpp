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
   int n,m;cin>>n>>m;
   vector<int> v(n);for(auto &i: v)cin>>i;
   vector<int> b(m);for(auto &i: b)cin>>i;
   v[0]=min(v[0],b[0]-v[0]);
   for(int i=1;i<n;i++){
    int val=b[0];
    if(v[i-1]+v[i]<=val && v[i-1]<=v[i]){
      v[i]=min(val-v[i],v[i]);
    }
    else if(v[i-1]+v[i]<=val){
      v[i]=val-v[i];
    }
    if(v[i-1]>v[i]){
      cout<<"NO";return;
    }
   }
   cout<<"YES";
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
        cout<<endl;
    }

    
    return 0;
}