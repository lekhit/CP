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
   char L='.';
   int i=0,j=0, d=1; //1=r
   vector<vector<char>> v(n, vector<char>(n));
   for(auto &i: v)for(auto &j: i) cin>>j;
   for(int i=0;i<n;i++){
    int cR=0, cB=0;
    for(int j=0;j<n;j++){
      if(v[i][j]=='R') cR++;
      if(v[j][i]=='B') cB++;
    }
    if(cR == 8){ cout<<'R'; return;}
    if(cB==8){ cout<<'B'; return;}
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