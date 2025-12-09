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
   vector<int> v(n), pre;
   for(auto &i: v){cin>>i;pre.push_back(i);}
   for(int i=1;i<n;i++){
    pre[i]+=pre[i-1];
   }
   int ans=0;

   auto getAheadZeros=[&](int i){
    return (i+1 < n)?(((n-1)-(i+1)+1)-(pre[n-1]-pre[i])):0;
   };
   auto getPreOnes=[&](int i){
    return i-1>=0?pre[i-1]:0;
   };
   for(int i=0;i<n;i++){
    if(v[i]==1){
      int zeros=getAheadZeros(i);
      ans+=zeros;
    }
   }

   int altAns=0;
   for(int i=0;i<n;i++){
    int delta=0;
    if(v[i]==1){
      delta=getPreOnes(i)-getAheadZeros(i);
    }else{
      // v[i]==0
      delta=(-getPreOnes(i)+getAheadZeros(i));
    }
    altAns=max(altAns, delta);
   }
   cout<<(ans+altAns);
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