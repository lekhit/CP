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

int solve() {
    // Your solution code here
    int n;cin>>n;
    vector<int> v(n);for(auto &i: v)cin>>i;

    auto canClimb=[&](int ladder){
      vector<int> vis(n, 0);
      for(int i=0;i<n;i++){
        if(vis[i]) continue;
        if(v[i]<=ladder) {vis[i]=1;
        // go forward
        for(int j=i+1;j<n;j++){
          if(abs(v[j]-v[j-1])<=ladder && !vis[j]){
            vis[j]=1;
          }else{
            break;
          }
        }
        //go back
        for(int j=i-1;j>=0;j--){
          if(abs(v[j]-v[j+1])<=ladder && !vis[j]){
            vis[j]=1;
          }else{
            break;
          }
        }}
      }
      for(auto i: vis) if(!i) return false;
      return true;
    };

    int lo=0, hi=100;
    while(lo<=hi){
      int mid=lo+(hi-lo)/2;
      if(canClimb(mid)){
        hi=mid-1;
      }else{
        lo=mid+1;
      }
    }
    return lo;
   
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
cin>>t;
   for(int i=1;i<=t;i++){
       int ans= solve();
      printf("Case #%d: %d\n",i, ans);
    }

    
    return 0;
}