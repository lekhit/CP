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
   vector<int> v(1001, -1);
   for(int i=1;i<=n;i++){
    int a;cin>>a;
    v[a]=i;
   }
   int ans=-1;
   for(int i=1;i<1001;i++){
    if(v[i]==-1) continue;
    for(int j=i;j<1001; j++){
      if(v[j]==-1) continue;
      if(gcd(i, j)==1){
        ans=max(ans, v[i]+v[j]);
      }
    }
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