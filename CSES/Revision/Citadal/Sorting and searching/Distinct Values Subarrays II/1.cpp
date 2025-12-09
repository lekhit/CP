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
   vector<int> v(n);for(auto &i: v)cin>>i;
   int i=0,j=0,c=0;
   set<int> s;
   while(j<n){
    s.insert(v[j]);
    while(s.size()>x){
      s.erase(v[i]);
      i++;
    }
    if(s.size()<=x){
      c++;
    }
    j++;
   }
   cout<<c;
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