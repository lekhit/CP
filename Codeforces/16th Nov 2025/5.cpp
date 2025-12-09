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
   int n, c;cin>>n>>c;
   vector<int> v(n);for(auto &i:v){cin>>i;
   }
   auto isPossible=[&](int w){
    int area=0;
    for(auto i: v){
      i+=(2*w);
      int a=(i*i);
      if(a<0 || a>c || area + a < 0 ) return false;
      (area+=(a));
      if(area <0 || area>c) return false;
    }
    return area<=c;
     };

     int lo=0, hi=1e9+7;
     while ((lo<=hi))
     {
      int mid=lo+(hi-lo)/2;
      // int sumAll=0;
      // for(int i: v){
      //   sumAll+=(i+2*mid)*(i+2*mid);
      //   if(sumAll > c) break;
      // }
      // if(sumAll==c){cout<<mid; return;}
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