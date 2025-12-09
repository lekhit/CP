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
   string t,s;cin>>t>>s;
   int i=0,j=0;
   while(i<t.size() && j< s.size()){
    if(t[i]==s[j] || t[i]=='?'){
      t[i]=s[j];
      i++; j++;
    }else{
      i++;
    }
   }
   if(j==s.size()){
    while(i<t.size()){
      if(t[i]=='?') t[i]='a';
      i++;
    }
    cout<<"YES\n";
    cout<<t;
   }else{
    cout<<"NO";
   }
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