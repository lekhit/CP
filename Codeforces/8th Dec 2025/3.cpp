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
    int n, flag=0, ans=0;cin>>n;
   for(int i=31;i>=0;i--){
      if(n&(1<<i)){
          if(!flag){
            ans|=(1<<i);
            flag=1;}
        }else{
          if(flag) 
            ans|=(1<<i);
        }
  }
   vector<int> v={ans, n, ans^n};
   sort(v.begin(), v.end());
   if(v[0]+v[1]<=v[2]){
    cout<<-1;
   }else{
    cout<<(ans^n);
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