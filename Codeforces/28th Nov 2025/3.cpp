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

    int getCost(int x){
      auto temp=pow(3, x-1);
      return (temp*9)+(x*temp);
    }

void solve() {
    // Your solution code here
   int n;cin>>n;
   vector<int> q, c;
   for(int i=1,j=0;i<(n+1);i*=3,j++){
    q.push_back(i);
    c.push_back((i*3+(i*j/3)));
   }
   reverse(c.begin(), c.end());
   reverse(q.begin(), q.end());
   int ans=0, deals=0;
   for(int i=0; i<c.size();i++){
    if(q[i]<=n){
      int t=(n/q[i]);
      ans+=c[i]*t;
      n%=q[i];
      deals+=t;
    }
   }
   cout<<ans;
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