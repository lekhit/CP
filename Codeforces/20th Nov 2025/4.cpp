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
   vector<int> v(n);for(auto &i: v)cin>>i;
   int i=0, j=n-1;
   for(int c=0; c<n;){
    if(i+1 < n && v[i+1]<=v[i]){
      i++; 
    }
    else if(j-1 >= 0 && v[j-1]<=v[j]){
      j--; c++;
    }else c++;
   }
   if(i>=j){
    cout<<"YES";
   }else cout<<"NO";
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