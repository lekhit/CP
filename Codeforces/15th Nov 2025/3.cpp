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

vector<vector<int>> v(10, vector<int>(10, 0));


void solve() {
    // Your solution code here
   int n=10, sum=0;
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      char ch;cin>>ch;
      if(ch=='X') sum+=v[i][j];
    }
   }
   cout<<sum;
}

int32_t main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }
       for(int row=0;row<5; row++){
    for(int col=0;col<row+1; col++){
      v[row][9-col]=v[row][col]=col+1;
      v[9-row][9-col]=v[9-row][col]=col+1;
    }
    for(int col=row;col<5; col++){
      v[9-row][9-col]=v[row][col]=row+1;
      v[row][9-col]=v[9-row][col]=row+1;
    }
   }

int t=1;
cin>>t;
    while(t--) {
        solve(); 
cout<<"\n";
    }

    
    return 0;
}