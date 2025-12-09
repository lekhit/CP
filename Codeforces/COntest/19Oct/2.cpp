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

void solve() {
    // Your solution code here
   int n;cin>>n;
   vector<int> v(n);for(auto &i: v)cin>>i;
   int m=v[0],c=0;
   if(n>2){
    if(v[0]>=v[1]){
      c+=1;
      v[0]-=1;
    }
   }
   for(int i=0;i<n;i++){
    m=max(v[i],m);
    if(i&1){
      v[i]=m;
    }else{
      if(i-1> 0 && v[i]>=v[i-1])
      {c+=(v[i]-v[i-1])+1;
      v[i]=v[i-1]-1;}
    }
   }
   cout<<c<<'\n';
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