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
#define int long long
void solve() {
    // Your solution code here
   int n;cin>>n;
   vector<int> v(n);for(auto &i:v)cin>>i;
   int c=0, ans=0, flag=1; // in case of all negative give one with least negative value;
   for(auto i: v){
    if(i>0) flag=0;
    if(c+i < 0) c=0;
    else c+=i;
    ans=max(ans, c);
   }
   if(flag) ans=*max_element(v.begin(), v.end());
   cout<<ans;
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