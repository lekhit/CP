#include <bits/stdc++.h>
using namespace std;
//accepted solution

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

void solve(){
int n;cin>>n;
queue<int> q;
vector<int> ans;
for(int i=1;i<=n;i++)q.push(i);
while(!q.empty()){
    int i=q.front();q.pop();q.push(i); // remove the first element and then push this back of the queue ie we are taking this element again 
    int j=q.front();q.pop();// the second element is rejected 
    ans.push_back(j);
}
for(auto i:ans)cout<<i<<" ";
}

int main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

    solve();
    
    return 0;
}