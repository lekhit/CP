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
   vector<int> v(10, 0);
   string s="01032025";
   int c=0;
   for(auto i:s){
    v[i-'0']++;
    c++;
   }
   int ans=0;
   for(int i=0;i<n;i++){
    int a;cin>>a;
    if(c==0) continue;
    if(v[a]>0){
      v[a]--;
      c--;
    }
    ans++;
   }
   if(c==0) cout<<ans;
   else cout<<0;
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
cin>>t;
    while(t--) {
        solve(); 
cout<<"\n";
    }

    
    return 0;
}