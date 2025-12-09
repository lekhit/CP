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
  int h=0, v=0;
  for(auto i: s){
    if(i=='U'){
      v++;
    }else if(i=='D'){
      v--;
    }

    if(i=='R'){
      h++;
    }else if(i=='L'){
      h--;
    }
    if(h==1 && v==1){
      cout<<"YES"; return;
    }
  }
  cout<<"NO";
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