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
   string s;
   getline(cin, s);
   int n=s.size();
   string ans="";
ans+=s[0];
   for(int i=0;i<n;i++){
    if(i+1 < n && s[i]==' ' && s[i+1]!='\n'){
      ans+=s[i+1];
    }
   }
   cout<<ans<<endl;
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
cin>>t;string s;getline(cin, s);
    while(t--) {
        solve();
    }

    
    return 0;
}