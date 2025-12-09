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
   int n,k;cin>>n>>k;
   vector<pair<int,int>> v(n);for(auto &[a,b]:v)cin>>b>>a;// storing by end 
   sort(v.begin(),v.end());
   multiset<int> endings;
    for(int i=0;i<k;i++)endings.emplace(0);
    int ans=0;
   for(auto [end, start]:v){
    auto it=endings.upper_bound(start);//get the element which is just higher than the required start time; one element before it would be lower than the start time
    // unless is it is beginning
    if(it==begin(endings)) continue; // no place for the movie
    --it; // move to movie which has finished just before new movie begins. 
    /* why not go for approch where we take the first finised movie?
    --> because we want to keep the greedy approach where
    the movie that finished first will be kept for the lower start point that may show up later
    ie we take the immediate best position keeping the best position for later chances. 
    */
   endings.erase(it);
   endings.insert(end);
   ans++;
   }
   cout<<ans;
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