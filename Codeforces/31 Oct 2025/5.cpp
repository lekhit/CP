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
   int n,k,l,r;cin>>n>>k>>l>>r;
   map<int, int> ms1, ms2;
   vector<int> v(n);for(auto &i: v)cin>>i;
   int count=0;
   for(int i=0,j=0,rightEnd=0;i<=n-k;i++){
    while(j<n && ms1.size()<k){
      if(ms1.count(v[j])){
        ms1[v[j]]++;
      }else{
        ms1[v[j]]=1;
      }
      if(ms1.size() == k){
        break;
      }
      j++;
    }
    while(rightEnd<n){
      if(ms2.count(v[rightEnd])){
        ms2[v[rightEnd]]++;
      }else{
        ms2[v[rightEnd]]=1;
      }
      if(ms2.size()>k){
        break;
      }
      rightEnd++;
    }
    count+=(min(i+r-1, rightEnd-1)-max(i+l-1, j)+1);
    ms1[v[i]]--;
    ms2[v[i]]--;
    if(ms1[v[i]]==0) ms1.erase(v[i]);
    if(ms2[v[i]]==0) ms2.erase(v[i]);
   }
   cout<<count<<'\n';
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
    }

    
    return 0;
}