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
  vector<pair<int,int>> v(n);for(auto &[end, start]:v)cin>>start>>end;
  sort(v.begin(),v.end());
  multiset<int> st;
  int c=0;
  for(auto [end, start]: v){
    auto it=st.lower_bound(-start);
    if(it!=st.end()){
      st.erase(it);
    }
    if(st.size()<k){
      c++;
      st.insert(-end);
    }
  }
  cout<<c;
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