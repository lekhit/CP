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
  int n,x;cin>>n>>x;
  vector<pair<int,int>> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i].first;
    v[i].second=(i+1);
  }
  sort(v.begin(), v.end());
  int i=0,j=n-1;
  while(i<j){
    if(v[i].first+v[j].first==x){
      cout<<v[i].second<<" "<<v[j].second;
      return;
    }else{
      if(v[i].first+v[j].first<x){
        i++;
      }else{
        j--;
      }
    }
  }
  cout<<"IMPOSSIBLE";
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
//cin>>t;
    while(t--) {
        solve();
    }

    
    return 0;
}