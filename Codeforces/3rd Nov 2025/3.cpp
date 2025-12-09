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
   vector<int> v(n*2+1, -1);
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){ 
      cin>>v[i+j+2];
    }
   }
   set<int> s(v.begin(), v.end());
   int missing=-1;
   for(int i=1;i<=2*n;i++){
    if(!s.count(i)){missing=i; break;}
   }
   for(int i=1;i<(2*n+1);i++){
    if(v[i]==-1){
      cout<<missing;
    }else{
      cout<<v[i];
    }
    cout<<" ";
   }
   cout<<endl;
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
    }

    
    return 0;
}