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
   int n=8;
   vector<vector<char>> v(n, vector<char>(n));
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>v[i][j];
    }
   }
   int a,b;
   for(int i=1;i<n-1;i++){
    for(int j=1;j<n-1;j++){
      if(v[i-1][j-1]=='#' && v[i-1][j+1] == '#' && v[i+1][j+1]=='#' && v[i+1][j-1]=='#'){
        a=i+1; b=j+1;
      }
    }
   }
   cout<<a<<" "<<b;
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