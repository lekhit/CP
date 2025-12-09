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
   int n;cin>>n;
  vector<int> v(n), ans;for(auto &i: v) cin>>i;
  int x=0, y=n-1, takeX=1;
  while(x<=y){
    if(takeX){
      ans.push_back(v[x]);
      x++;
      takeX=0;
    }else{
      ans.push_back(v[y]);
      y--;
      takeX=1;
    }
  }
  for(auto i: ans) cout<<i<<" ";
  cout<<"\n";
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