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
   int n;cin>>n;
   int MOD=1e9+7;
   int fMin=1e9+7, sMin, bMin;
   sMin=bMin=fMin;
   for(int i=0;i<n;i++){
    int a;cin>>a;string s;cin>>s;
    if(s=="10"){
      fMin=min(fMin, a);
    }
    if(s=="11"){
      bMin=min(bMin, a);
    }
    if(s=="01"){
      sMin=min(sMin, a);
    }
   }
   if(bMin!=MOD && (sMin==MOD || fMin==MOD)){
    cout<<bMin; return;
   }
   if(bMin==MOD && (sMin==MOD || fMin==MOD)){
    cout<<-1; return;
   }
   if(fMin+sMin < bMin){
    cout<<(fMin+sMin); return;
   }else{
    cout<<bMin;
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