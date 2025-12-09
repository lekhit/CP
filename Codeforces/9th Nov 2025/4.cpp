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
   int n,m;cin>>n>>m;
   int firstC=0, fc=0, minJ=m, rowN=0;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char ch;cin>>ch;
      if(!fc && ch=='#'){
        firstC=j;
        fc=1;
      }
      if(ch=='#'){
        if(minJ>j){
          minJ=j;
          rowN=i;
        }
      }
    }
   }
   cout<<(rowN+1)<<" "<<(firstC+1);
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