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
   vector<int> xorEdges, visEdges(m,0), deg(n+1), inDeg(n+1), outDeg(n+1);
   vector<vector<int>> grp(n+1);
   for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    xorEdges.push_back(a^b);
    grp[a].push_back(i);
    inDeg[b]++;
    outDeg[a]++;
    deg[a]++;deg[b]++;
   }
   if(!(deg[1] & 1) || !(deg[n] & 1)){
    cout<<"IMPOSSIBLE"; return;
   }
   for(int i=2;i<n;i++){
    if(outDeg[i]!=inDeg[i]){ // needed to ensure that there is a way out of each node
        cout<<"IMPOSSIBLE"; return;
    }
   }
   vector<int> ans;
   stack<int> st;
   st.push(1);
   while ((!st.empty()))
   {
    int top=st.top();
    if(deg[top]==0){
        ans.push_back(top);
        st.pop();
    }else{
        for(int index=grp[top].size()-1;index>=0;index--){
            int edge=grp[top][index];
            if(!visEdges[edge]){
                visEdges[edge]=1;
                int connectedNode=xorEdges[edge]^top;
                st.push(connectedNode);
                deg[top]--;
                deg[connectedNode]--;
                break;
            }else{
                grp[top].pop_back();
            }
        }
    }
   }
 
   for(int i=0;i<m;i++){
    if(!visEdges[i]){
        cout<<"IMPOSSIBLE";return;
    }
   }
   reverse(ans.begin(), ans.end());
   for(auto i: ans) cout<<i<<" ";
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
