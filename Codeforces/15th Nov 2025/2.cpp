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
   vector<int> v(n);
   int product=1,iP=1;;
   for(auto &i: v){
    cin>>i;
    if(i!=0) product*=i;
   }
   iP=product;
   int z=0, ans=0;
   for(int i: v){
    if(i!=0){
      int temp=product;
      temp/=i;
      temp*=(i+1);
      ans=max(ans, temp);
    }else{
      z++;
    }
    
   }
   if(z>1){
    cout<<0;
    return;
   }
   if(z==1){
    cout<<product;
   }
   else{
    cout<<ans;
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