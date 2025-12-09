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
   stack<pair<int,int>> st;
   for(int i=0;i<n;i++){
    int a;cin>>a;
    while(!st.empty() && st.top().first >= a){
      st.pop();
    }
    if(!st.empty()){
      cout<<(st.top().second)<<' ';
    }else{
      cout<<0<<' ';
    }
    st.push({a, i+1});
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