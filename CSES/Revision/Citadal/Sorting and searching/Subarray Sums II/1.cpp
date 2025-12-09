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
   int n;cin>>n;
   vector<int> v(n);
   for(auto &i: v)cin>>i;
   for(int i=1;i<n;i++){
    (v[i]+=v[i-1]);
   }
   for(auto &i: v){
    i=((i%n)+n)%n;
   }
   map<int,int> mp;
   mp[0]=1;
   int c=0;
   for(int i=0;i<n;i++){
    if(mp.count(v[i]))
      c+=mp[v[i]];
    mp[v[i]]++;
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