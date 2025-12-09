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
   auto getSum=[&](int x, int k){
    return x*(k*(k+1))/2;
   } ;
   pair<int,int> ans={0,0};
   for(int x=1;x<=n;x++){
    for(int k=1;k<=n;k++){
      if(k*x <= n){
        ans=max(make_pair(getSum(x, k), x), ans);
      }
    }
   }
   cout<<ans.second;
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