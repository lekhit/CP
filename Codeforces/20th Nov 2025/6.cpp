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
   int n,c;cin>>n>>c;
   double d; cin>>d;
   vector<int> v(n);
   for(auto &i: v)cin>>i;
   sort(v.rbegin(), v.rend());

   auto isPos=[&](int k){
    int val=0;
    for(int i=0;i<=k && i<n;i++){
      int slots=ceil((d-i)/(k+1));
      int temp=(slots*v[i]);
      if(temp>=c) return true;
      val+=temp;
      if(val>=c) return true;
    }
    return val>=c;
   };
   if(v[0]*d < c) {cout<<"Impossible"; return;}
   if(isPos(d)) {cout<<"Infinity"; return;}
   int lo=0, hi=d-1;
   while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(isPos(mid)){
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