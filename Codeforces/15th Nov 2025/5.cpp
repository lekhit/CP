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
   int n,w;cin>>n>>w;
   int MOD=1e18+7;
   vector<int> v(n);for(auto &i: v)cin>>i;
   auto isPossible=[&](int h){
    int sum=0;
    for(auto i: v){
      if(h-i > 0){
        (sum+=h-i)%=MOD;
      }
    }
    return sum<=w;
   };
   int lo=0, hi=1e18;
   while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(isPossible(mid)){
      lo=mid+1;
    }else{
      hi=mid-1;
    }
   }
   cout<<hi;
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