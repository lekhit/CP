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
   int k;cin>>k;
   vector<int> a(n),b(n);
   for(auto &i: a)cin>>i;
   for(auto &i: b)cin>>i;

   int cc=-1, flag=0;
   for(int i=0;i<n;i++){
    if(b[i]!=-1){
      if(cc==-1){
        cc=a[i]+b[i];
      }else {
        if(cc!=a[i]+b[i]){
          flag=1;break;
        }
      }
    }
   }
   int ans=0;
   if(flag){
    cout<<0; return;
   }else{
     int m=(*min_element(a.begin(), a.end()));
      int mm=(*max_element(a.begin(), a.end()));
    if(cc==-1){
      // means all -1
      ans=(m+k)-mm+1;
    }else{
      if(m+k >= cc){
        if(mm > cc) ans=0;
        else 
          ans=1;
      }
    } 
   }
   cout<<ans;
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