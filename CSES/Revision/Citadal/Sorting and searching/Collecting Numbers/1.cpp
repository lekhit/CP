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
   int n,m;cin>>n>>m;
   map<int,int> mp;
   vector<pair<int,int>> v(n);
   for(int i=0;i<n;i++){
    int a;cin>>a; a--;
    v[i].first=a;
    v[i].second=i;
    mp[i]=a;
   }
   sort(v.begin(), v.end());
   int c=1;
   for(int i=1;i<n;i++){
    if(v[i-1].second >v[i].second){
      c++;
    }
   }
   while ((m--))
   {
    int a,b;cin>>a>>b;
    a--;b--;
    set<int> previousIndex;
  
    for(auto i: {0, 1}){
    previousIndex.insert(mp[a]+i);
    previousIndex.insert(mp[b]+i);
    }
    int previousImpact=0;
    for(auto i: previousIndex){
      if(i<n && i-1>=0){
        previousImpact+=v[i-1].second >v[i].second;
      }
    }
    swap(v[mp[a]].second,v[mp[b]].second);
    swap(mp[a], mp[b]);
    int newImpact=0;
    for(auto i: previousIndex){
      if(i<n && i-1>=0){
        newImpact+=v[i-1].second > v[i].second;
      }
    }
    c=c+newImpact-previousImpact;
    cout<<c<<endl;
   }
   

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