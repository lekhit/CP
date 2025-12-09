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
   int n, k;cin>>n>>k;
   vector<int> v(n), s;
   for(auto &i:v)cin>>i;
   sort(v.begin(), v.end());
   int c=1, valid=1, sum=0;
   for(int i=1;i<n;i++){
    if(v[i]-v[i-1] <= k){
      c++;
    }else{
      valid=max(valid, c);
      c=1;
    }
    valid=max(valid, c);
   }
   cout<<(n-valid);
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