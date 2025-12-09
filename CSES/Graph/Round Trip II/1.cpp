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
vector<vector<int>> grp;
vector<int> tin, tout, ans;
const int UNVISITED=-1;
int timer, foundCycle;
void dfs(int n){
    if(tin[n]!=UNVISITED){
        // visting second time;
        if(tout[n]==UNVISITED){
            // cycle found
            foundCycle=true;
            ans.push_back(n);
        }
        return;
    }
    tin[n]=++timer;
    for(auto i: grp[n]){
        if(foundCycle) break;
        dfs(i);
    }
    if(foundCycle) {
        ans.push_back(n);
    }
    tout[n]=++timer; 
}
vector<int> trimCycle(vector<int> ans){
    //since backtrack will have the cycle + elements that were in track till cycle.
    // this will trim the cyle out of the remaining track 
    int start=ans.front(); 
    vector<int> v;
    v.emplace_back(start);
    for(int i=1;i<ans.size();i++){
        v.emplace_back(ans[i]);
        if(ans[i]==start) break;
    }
    reverse(v.begin(), v.end()); // since it is directed graph so the answer obtained from the dfs will be reverse 
    return v;
}

void solve() {
    // Your solution code here
    timer=0;
    foundCycle=false;
   int n,m;cin>>n>>m;
   grp.resize(n+1);
   tin.assign(n+1, UNVISITED);
   tout.assign(n+1, UNVISITED);
   for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    grp[a].emplace_back(b);
   }
   for(int i=1;i<=n;i++)
    // if(!foundCycle) // avoids multiple cycles but even if multiple cycle are found then we are trimming the cycle
    dfs(i);

   if(ans.size()>0){
    auto temp=trimCycle(ans);
    cout<<(temp.size())<<"\n";
    for(auto i: temp) cout<<i<<" ";
   }else{
    cout<<"IMPOSSIBLE";
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