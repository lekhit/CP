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
   int n,x;
   cin>>n>>x;
   set<int> s;
   s.insert(0);
   s.insert(n);
   multiset<int> ms;
   ms.insert(n);
   for(int i=0;i<x;i++){
    int a;
    cin>>a;
    auto it=s.lower_bound(a);
    int end=(*it);
    int start=*(--it);
    s.insert(a);
    auto it2=ms.lower_bound(end-start);
    ms.erase(it2);
    ms.insert(a-start);
    ms.insert(end-a);
    cout<<(*ms.rbegin())<<'\n';
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