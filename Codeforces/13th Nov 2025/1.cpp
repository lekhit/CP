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
   int n=3;
   vector<int> v(n), v2;for(auto &i: v)cin>>i;
   v2=v;
   sort(v2.begin(), v2.end());
   if(v[0]<v[1] && v[1]< v[2]){
    cout<<"STAIR";
   }else{
   if(v[1]>v[0] && v[1]>v[2]){
    cout<<"PEAK";
   }else{
    cout<<"NONE";
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