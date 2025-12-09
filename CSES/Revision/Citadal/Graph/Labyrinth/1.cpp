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
   pair<int,int> start, end;
   vector<vector<int>> grp, parent;
   grp.assign(n, vector<int>(m, 1));
   parent.assign(n, vector<int>(m, 0));
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        char ch;cin>>ch;
        if(ch=='A') {start={i,j};}
        if(ch=='B') end={i,j};
        if(ch=='#') grp[i][j]=0;
    }
   }
   const int LEFT=1, RIGHT=4, UP=2, DOWN=3;
   queue<pair<int,int>> q;
   q.push(start);
   parent[start.first][start.second]=-1;
   parent[end.first][end.second]=1;
   while (!q.empty())
   {
    auto [x,y]=q.front();
    if(q.front()==end) break;
    q.pop();
    vector<tuple<int,int, int>> direction={{x+1, y, DOWN}, {x-1, y, UP}, {x, y-1, RIGHT}, {x, y+1, LEFT}};
    for(auto [a,b, c]: direction){
        if(a>=0 && b>=0 && a<n && b<m)
       { if(grp[a][b] && parent[a][b]==0)
        {q.push({a,b});
        parent[a][b]=c;}
    }
    }
   }

   // reiterate to get the path
   vector<char> ans;
   if(parent[end.first][end.second]==0){
    cout<<"NO";return;
   }else{
    cout<<"YES";
    auto node=end;
    while(node!=start){
        auto [x,y]=node;
        auto direct=parent[x][y];
        vector<tuple<int,int, int, char>> direction={{x, y-1, LEFT, 'R'}, {x, y+1, RIGHT, 'L'}, {x+1, y, UP, 'D'}, {x-1, y, DOWN, 'U'}};
        auto parentTuple=direction[direct-1];
        auto [newX, newY, _, ch]=parentTuple;
        x=newX; y=newY;ans.push_back(ch);
        node={x,y};
    }
    cout<<ans.size()<<"\n";
for(auto i: ans) cout<<i<<" ";
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