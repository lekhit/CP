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
   int n,m;
   cin>>n;//>>m; m--;
   vector<int> v(n), pre(n);cin>>v[0];

   pre[0]=v[0];
   for(int i=1;i<n;i++){
    cin>>v[i];
    // v[i]+=v[i-1];
    pre[i]=pre[i-1]+v[i];
   }
  int lo=0, hi=n-1;
  while(lo<hi){
    int mid=lo+(hi-lo)/2;
    int a=0;
    
    cout<<"? "<<(mid-lo+1)<<" "<<flush;
    for(int i=lo;i<=mid;i++){
      cout<<(i+1)<<" ";
      // a+=v[i];
      // if(i==(m)) a++;
    }cout<<endl<<flush;
    cin>>a;
int b=pre[mid]-((lo-1>=0)?pre[lo-1]:0);
    if(a==b){
      lo=mid+1;
    }
    else{
      hi=mid;
    }
  }
  cout<<"! "<<(lo+1)<<endl<<flush;
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
// cout<<"\n"<<flush;
    }

    
    return 0;
}