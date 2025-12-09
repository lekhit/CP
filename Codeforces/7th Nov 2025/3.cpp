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
    int m,a,b,c;
    int a1=0,b1=0;
    cin>>m>>a>>b>>c;
    int ans=0;
    if(a>m){
      a1+=m;
    }else{
      a1+=a;
      auto t=min(m-a1, c);
      c-=t;
      a1+=t;
    }

    if(b>m){
      b1+=m; 
    }else{
      b1+=b;
      auto t=min(m-b1, c);
      b1+=t;
    }
    cout<<(a1+b1);
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
        cout<<endl;
    }

    
    return 0;
}