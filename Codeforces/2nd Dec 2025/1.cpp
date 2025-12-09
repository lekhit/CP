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
   int s;cin>>s;
   vector<int> v(n);for(auto &i:v)cin>>i;
   int m1=(*min_element(v.begin(), v.end())), m2=(*max_element(v.begin(), v.end()));
  int ans=0;
   if(m1 < s and m2 < s) ans=s-m1;
   else if(m1>s and m2>s) ans=m2-s;
   else 
   ans=(min(s-m1, m2-s)*2+max(s-m1, m2-s));
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