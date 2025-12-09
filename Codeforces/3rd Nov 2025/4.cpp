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
   string o, h;
   cin>>o>>h;
  //  char now;
  if(o.size()>h.size()) {cout<<"NO"<<endl;return;}
   int c=0;
   for(int i=0,j=0;i<o.size() && j<h.size();i++, j++){
    if(i>0 && o[i-1]!=o[i]){
      // changed
      while(h[j]!=o[i] && c>0){
        c--; j++;
      }
      c=0;
    }
    if(h[j]!=o[i]){
      c=-1;
      break;
    }
    c++;
   }
   if(c==-1) cout<<"NO";
   else cout<<"YES";
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