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

    int conv(char ch)
{
  return ch-'0';
}
void solve() {
    // Your solution code here
    string s;cin>>s;
    reverse(s.begin(), s.end());
    int flag=0, c=0;
    int i=0;
    for(;i<s.size();i++){
      if(conv(s[i]) == 0){
        c++;
      }else{
        flag=1;
        i++;
        break;
      }
    }
    for(;i<s.size(); i++){
      if(conv(s[i])!=0) c++;
    }
    cout<<c;
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