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
    int MOD=1e18+7;
   int h,n;cin>>h>>n;
   vector<int> attack(n), cool(n);
   for(auto &i: attack)cin>>i;
   for(auto &i: cool)cin>>i;
   auto canDefeat=[&](int turns){
    int damage=0;
    for(int i=0;i<n;i++){
      int a=(attack[i]*((turns+cool[i]-1)/cool[i]));
      if(a>=h || a<0) return true;
      damage+=a;
      if(damage>=h) return true;
    }
    return h<=damage;
   };
   int lo=0, hi=1e18;
   while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(canDefeat(mid)){
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
cin>>t;
    while(t--) {
        solve(); 
cout<<"\n";
    }

    
    return 0;
}