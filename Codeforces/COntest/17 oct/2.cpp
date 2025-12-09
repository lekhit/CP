#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

bool isPal(string s){
  int n=s.size();
  for(int i=0;i<(n/2);i++){
    if(s[i]!=s[n-i-1]) return false;
  }
  return true;
}
void solve() {
    // Your solution code here
   int n;cin>>n;
   string s;cin>>s;
   string firstHalf="", secondHalf="";
   if(n==0) {cout<<-1;return;}
   vector<int> ans;
   int l=0, r=0;
   for(int i=0;i<n;i++){
    firstHalf=s.substr(i, l);
    secondHalf=s.substr(r+1, n-r);
    if(isPal(firstHalf+secondHalf)){
      cout<<(r-l+1)<<endl;
      for(int j=l+1;j<=r+1;j++){
        cout<<j<<" ";
      }
      cout<<endl;
      return;
    }
   }
   cout<<-1<<endl;
}

int main() {
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