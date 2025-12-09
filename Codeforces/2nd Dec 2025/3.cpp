#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define int long long
#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)


    void solve1(){
      int r, c,m=0;
    cin>>r>>c;
    vector<vector<int>> v(r, vector<int>(c));
    for(auto &i: v)for(auto &j: i){cin>>j;m=max(m, j);}
      vector<pair<int,int>> temp;
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        if(v[i][j]==m){
          if(temp.empty()){
            temp.push_back({i,j});
          }else{
            if(i==temp[0].first || j==temp[0].second) continue;
            else{
              temp.push_back({i,j});break;
            }
          }
        }
      }
      if(temp.size()>1) break;
    }
    
    }
void solve() {
    // Your solution code here
    int r, c;
    cin>>r>>c;
    vector<vector<int>> v(r, vector<int>(c));
    int m=0;
    vector<int> rowIndex, colIndex;
    map<int,int> rmp, cmp;
    for(auto &i: v)for(auto &j: i){cin>>j;m=max(m, j);}
    for(int i=0;i<r;i++)for(int j=0;j<c;j++){
      if(v[i][j]==m){
        rowIndex.push_back(i);
        colIndex.push_back(j);
        rmp[i]++;
        cmp[j]++;
      }
    }   
    int flag=1;
    auto rM=(*max_element(rmp.begin(), rmp.end(), [&](auto a, auto b ){return a.second<b.second;}));
    auto cM=(*max_element(cmp.begin(), cmp.end(), [&](auto a, auto b ){return a.second<b.second;}));
    auto [colVal, colCount]=cM;
    auto [rowVal, rowCount]=rM;

    int fC=colIndex[0], fR=rowIndex[0];
    int sC=fC, sR=fR;
    for(int i=0;i<rowIndex.size(); i++){
      if(rowIndex[i]!=sR && colIndex[i]!=sC){
        sR=rowIndex[i];
        sC=colIndex[i];
        break;
      }
    }
    // for(int i=0;i<rowIndex.size();i++){
    //     if(!(rowIndex[i]==rowVal || colIndex[i]==colVal)){
    //       {
    //         flag=0;break;
    //       }
    //     }
    // }
    cout<<(m-flag);
    
}

int32_t main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

int t=1;
cin>>t;
    while(t--) {
        solve(); 
cout<<"\n";
    }

    
    return 0;
}