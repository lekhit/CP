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

class Node{
    public:
    int x,y;
    char val;
    int id;
    int parentId;
    char parentDirection;
    Node(int x, int y, int id, char val){
        this->x=x;
        this->y=y;
        this->id=id;
        this->val=val;
    }
};

void solve() {
    // Your solution code here
   int n,m;cin>>n>>m;
   vector<vector<char>> grp(n, vector<char>(m));
   
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