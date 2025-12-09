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


int  solve2(int n,vector<vector<int>> v){
    vector<pair<int,int>> v1;
    for(auto i: v){
        v1.push_back({i[1],i[0]});
    }
    sort(v1.begin(),v1.end());
    int timetaken=0;
    for(auto [end, time]:v1){
        if(timetaken + time > end){
            return -1;
        }else{
            timetaken+=time;
        }
    }
    return timetaken;
   }

void solve() {
    // Your solution code here
  
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