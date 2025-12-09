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
   int n,k, kCount=0;cin>>n>>k;
  vector<int> v(n);
  for(auto &i: v) {cin>>i;kCount+=(i==k);}
  set<int> s;
  s.insert(v.begin(), v.end());
  int mex=0, ans=kCount;
  for(int i=0;i<n;i++){
    if(i==k){
      break;
    }
    if(!s.count(i)){
      if(kCount>0) kCount--;
      else ans++;
    }
  }
  cout<<ans<<"\n";

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
    while(t--) {
        solve();
    }

    
    return 0;
}