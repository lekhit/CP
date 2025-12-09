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
   int n,k;cin>>n>>k;
   vector<int> v(n);for(auto &i: v)cin>>i;
   vector<int> cnt(2, 0);
   int i=0,j=0;
   while(j<n && j<k){
    cnt[v[j]]++;
    j++;}
int c=0;
    while(j<n){
      if(cnt[1]==0){
        c++; // success
        j++;
        i=j;
        cnt[0]=0; cnt[1]=0;
        while(j<n && (j-i)<k){
          cnt[v[j]]++;
          j++;
        }
      }else{
        // not found;
        cnt[v[j]]++;
        cnt[v[i]]--;
        j++;
        i++;
      }
    }
    if(j-i == k){
      if(cnt[1]==0) c++;
    }
    cout<<c;
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