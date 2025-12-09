#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

void solve() {
    // Your solution code here
   int n,k;cin>>n>>k;
   vector<int> v;
   v.push_back(0);
   for(int i=0;i<n;i++){
    int a;cin>>a;v.push_back(a);
   }
   vector<int> pre(n*2+1);
  //  v.insert(v.end(), v.begin()+1, v.end());
   for(int i=1;i<=(n);i++){
    v[i]+=v[i-1];
   }
   // check for v later
   int ans=0;
   for(int i=1;i<=n;i++){
      int lo=i, hi=n;
      while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]-v[i-1] <= k){
          lo=mid+1;
        }else{
          hi=mid-1;
        }
      }
      ans=max(hi-i+1, ans);
   }
   cout<<ans;

}

int main() {
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