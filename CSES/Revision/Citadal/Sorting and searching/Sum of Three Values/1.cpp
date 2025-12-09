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
   int n,x;cin>>n>>x;
   vector<pair<int,int>> v(n);
   int c=1;
   for(auto &[a,b]:v) {cin>>a; b=c++;}
   sort(v.begin(), v.end());
   for(int j=0;j<n;j++)
   for(int i=j+1;i<n;i++){
    int lo=i+1, hi=n-1, sum=x-v[i].first-v[j].first;
    while(lo<hi){
      if(v[lo].first+v[hi].first == sum) {
      cout<<v[i].second<<" "<<v[lo].second<<" "<<v[hi].second<<" "<<v[j].second;
      return;
      };
      if(v[lo].first+v[hi].first < sum){
        lo++;
      }else{
        hi--;
      }
    }
    
   }
   cout<<"IMPOSSIBLE";
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
//cin>>t;
    while(t--) {
        solve();
    }

    
    return 0;
}