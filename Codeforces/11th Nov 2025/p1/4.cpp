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

pair<int,int> count(string s){
  int ones=0, zeros=0;
  if(s[0]=='1') ones++;
  else zeros++;
  for(int i=1;i<s.size();i++){
    if(s[i-1]!=s[i]){
      if(s[i]=='1') ones++;
      else zeros++;
    }
  }
  return make_pair(ones, zeros);
}

void solve() {
    // Your solution code here
   string s;cin>>s;
   
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