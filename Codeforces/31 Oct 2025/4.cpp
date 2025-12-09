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
#define int long long
void solve() {
    // Your solution code here
   int n;cin>>n;
   string s;cin>>s;
   vector<int> a,b;
   for(int i=0;i<n;i++){
    if(s[i]=='a') a.push_back(i);
    else b.push_back(i);
   }
   auto getCost=[&](int mid, char ch)->int {
    int midA=mid;
   int l=midA,r=midA;
   int cost=0, totalCost=0;
   while(l>=0){
    if(s[l]==ch) cost++;
    else{
      totalCost+=cost;
    }
    l--;
   }
   cost=0;
   while(r<n){
    if(s[r]==ch) cost++;
    else totalCost+=cost;
    r++;
   }
   return totalCost;
   };

   int ans=1e18+7;
   if(a.size()>0)
    ans=min(getCost(a[a.size()/2], 'b'), ans);
   if(b.size()>0)
    ans=min(getCost(b[b.size()/2], 'a'), ans);
   cout<<ans<<"\n";
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