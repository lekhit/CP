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

int compare(string s1, string s2){
  int ans=0;
  for(int i=0;i<s1.size(); i++){
    ans+=abs(s1[i]-s2[i]);
  }
  return ans;
}

void solve() {
    // Your solution code here
   int n,m;cin>>n>>m;
   vector<string> v(n);for(auto &i: v)cin>>i;
   sort(v.begin(), v.end(), [&](string a, string b){return compare(a, b);});
  int ans=compare(v[0], v[n-1]);
  for(int j=1;j<n;j++){
  //  for(int i=0;i<n;i++){
    // if(i==j) continue;
    ans=min(compare(v[j-1], v[j]), ans);
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