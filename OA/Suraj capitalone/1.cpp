
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


class myMat{
  public:
  myMat(vector<vector<string>> m){
    mat=m;
    int x,y;
    set<int> s;
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        if(m[i][j]=="?") {
          x=i;y=j;
        }else{
          s.insert(stoi(m[i][j]));
        }
      }
    }
    for(int i=1;i<=16;i++){
      if(!s.count(i)) {
        missing=i;
        break;
      }
    }
    mat[x][y]=to_string(missing);
  }
  int missing;
  vector<vector<string>> mat;
};

class myMat2{
  public:
  int missing;
  vector<string> mat;
  myMat2(vector<string> ss){
    set<int> mySet;
    int x=0;
    for(int i=0;i<ss.size();i++){
      if(ss[i]=="?") {
        x=i;
      }else{
        mySet.insert(stoi(ss[i]));
      }
    }
    for(int i=1;i<=16;i++){
      if(!mySet.count(i)) {
        missing=i;
        break;
      }
    }
    ss[x]=to_string(missing);
    mat=ss;
  }
};


vector<vector<string>> solve2(vector<vector<string>> mat){
  vector<myMat2> matrix;
   for(auto i: mat){
    matrix.push_back(myMat2(i));
   }

    auto compare=[](myMat2 a, myMat2 b){
      return a.missing < b.missing;
    };

    sort(matrix.begin(), matrix.end(), compare);

    vector<vector<string>> ans;
    for(auto i: matrix){
      ans.push_back(i.mat);
    }
    return ans;
}

void solve() {
  int n;cin>>n;
  vector<string> temp;
  vector<vector<string>> ss;
  while(n--){
    for(int i=0;i<16;i++){
      string s;cin>>s;
      temp.push_back(s);
    }
    ss.push_back(temp);
    temp.clear();
  }
  auto ans=solve2(ss);
  for(auto i: ans){
    for(auto j: i){
      cout<<j<<" ";
    }
    cout<<endl;
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