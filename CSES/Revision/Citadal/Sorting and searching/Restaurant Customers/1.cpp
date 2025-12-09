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
   int n;cin>>n;
   priority_queue<int> pq;
   // need a min heap
   int c=0;
   vector<pair<int,int>> v(n);
   for(auto &[start, end]:v){
  cin>>start>>end;
   }
   sort(v.begin(), v.end());
   for(auto [a, b]:v){
      while (!pq.empty() && pq.top()>(-a))
      {
        pq.pop();
      }
      pq.push(-b);
    c=max((int)pq.size(), c);
   }
   cout<<c;
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