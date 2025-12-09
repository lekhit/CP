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
   int rKeeper=0, blockKeeper=1, colKeeper=1;
   for(int i=0;i<(n<<1);i++,rKeeper++){
    for(int j=0;j<(n<<1);j++,colKeeper++){
    if(rKeeper>=2){
      rKeeper=0;
      blockKeeper=!blockKeeper;
    }
    if(blockKeeper){
      if(colKeeper){
        cout<<"#";
      }
    }
   }
  }

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