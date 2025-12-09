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
   int n, k,q;cin>>n>>k>>q;
   vector<pair<double,int>> a;
   a.push_back({0,0});
   vector<int> b;
   b.push_back(0);
   for(int i=1;i<=k;i++){double m;cin>>m; a.push_back({m, i});}
   for(int i=0;i<k;i++){int m;cin>>m;
    b.push_back(m);
   }
   while(q--){
    double d;cin>>d;
    auto it=lower_bound(a.begin(), a.end(), make_pair(d, 0LL));
    if(it!=a.end()){
    auto [a2, index]=(*it);
    if(a2==d){
      cout<<b[index];
    }else{
      double speed=(a[index].first-a[index-1].first)/(b[index]-b[index-1]);
      double timeNew=(d-a[index-1].first)/speed;
      double finalTime=b[index-1]+timeNew;
      cout<<(int)(floor(finalTime));
    }
   }
  cout<<" ";
  }


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