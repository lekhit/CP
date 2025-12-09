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
   int n,x;cin>>n>>x;
   vector<int> v(n);
   int f=0, s=0, flag=0;
   int c=0;
   for(auto &i: v) { cin>>i;
    if(i==1){
      if(!flag){ f=c;flag=1;}
      else {
        s=c;
      }
    }
    c++;
  }

  if(s<=f){
    cout<<"YES";return;
  }else{
    if(s-f+1 > x){
      cout<<"NO";
    }else{
      cout<<"YES";
    }
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