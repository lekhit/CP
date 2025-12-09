#include <bits/stdc++.h>
using namespace std;
 
// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

 #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); printf("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)
#define MP(a, b) make_pair(a,b)
const int MOD=1e9+7;
int N;
const int M=26;
typedef pair<int,int> pi;
vector<string> inp;
vector<vector<vector<int>>> dp;
vector<vector<int>> grp;
 
void printDP() {
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            cout << "dp[" << i << "][" << j << "]: ";
            for (int k = 0; k < dp[i][j].size(); ++k) {
                cout << dp[i][j][k] << ":"<<char('A'+k)<<" ";
            }
            cout << endl;
        }
    }
}
 
void build(){
    for(int i=N-1;i>=0;i--){
        for(int j=N-1;j>=0;j--){
            auto &compArr=dp[i][j];
            compArr[grp[i][j]]=i+j;
 
            if(i+1 < N){
                auto &rCompArr=dp[i+1][j];
                for(int I=0;I<M;I++){
                    compArr[I]=min(compArr[I], rCompArr[I]);
                }
            }
            if(j+1 < N){
                auto &dCompArr=dp[i][j+1];
                for(int I=0;I<M;I++){
                    compArr[I]=min(compArr[I], dCompArr[I]);
                }
            }
        }
    }
    // printDP();
}
 
const int DOWN=1;
const int RIGHT=2;
const int LAST=3;
 
int decideEqual(int i, int j){
    map<int,int> left, right;
    for(int I=M-1;I>=0;I--){
        left[dp[i+1][j][I]]=I;
        right[dp[i][j+1][I]]=I;
    }
    for(auto itl=left.begin(),itr=right.begin(); itl!=left.end() && itr!=right.end(); itl++, itr++){
        auto [kL, chL]=(*itl);
        auto [kR, chR]=(*itr);
        if(chL == chR) continue;
        if(chL < chR) return DOWN;
        else return RIGHT;  
    }
    return DOWN;
}
 
int decide(int i, int j){
    if(i>=N && j>=N) return LAST; // when on last index;
    if(i+1 < N && j+1 < N){
        // when both exist
        if(grp[i+1][j] == grp[i][j+1]){
            return decideEqual(i, j);
        }else{
            return grp[i+1][j] < grp[i][j+1] ? DOWN : RIGHT;
        }
    }else{ // only one exist return that one
        return i+1 < N ? DOWN: RIGHT;
    }
}
 
string move(){
    string ans="";
    int i=0,j=0;
    while(!(i>=N || j>=N)){
        ans+=inp[i][j];
        int decision=decide(i,j);
        if(decision==LAST){
            return ans;
        }
        if(decision==DOWN){
            i+=1;
        }else{
            j+=1;
        }
    }
    return ans;
}
 
void solve() {
    // Your solution code here
    cin>>N;
    inp.resize(N);
    dp.resize(N, vector(N, vector<int>(M ,MOD)));
    for (auto &i : inp)
    {
        cin >> i;
        vector<int> temp;
        for (char j : i)
        {
            temp.push_back((j - 'A'));
        }
        grp.push_back(temp);
    }
    build();
    cout<<move();
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
        time__("solve"){
        solve();}
    }
 
    
    return 0;
}