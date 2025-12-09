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
   int n,x; cin>>n>>x;
   vector<int> v(n);for(auto &i:v)cin>>i;
   map<int,int> mp;
   for(int i=1;i<n;i++){
    v[i]+=v[i-1];
   }
   int count=0;
   for(auto i: v){
    if(i==x) count++;
    auto it = mp.find(i-x);
    if(it!=end(mp)){
        count+=(*it).second;
    }
    mp[i]++;
   }
   cout<<count;

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