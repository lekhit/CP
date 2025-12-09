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
   int maxrow=0, c=0;
   for(int j=0;j<n;j++){
    int r=0;
   for(int i=0;i<n;i++){
    char a;cin>>a;
    if(a=='1'){
      r++;
    }
   }
  maxrow=max(maxrow, r);
  c+=r;
  }
  if(maxrow*maxrow == c){
    cout<<"SQUARE";
  }else {
    cout<<"TRIANGLE";
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