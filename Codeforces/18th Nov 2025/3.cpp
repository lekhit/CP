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
   string s;cin>>s;
   int c=1, possible=1;
   map<char, int> mp;
   for(auto i: s){
    if(mp.count(i)){
      if(mp[i]!=c){
        possible=0;break;
      }
    }
    else{
        mp[i]=c;
      }
    c=!c;
   }
   cout<<(possible?"YES":"NO");
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