#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MP(a, b) make_pair(a, b)
const int MOD = 1e9 + 7;
int N;
const int M = 26;
typedef pair<int, int> pi;
vector<string> inp;

vector<vector<int>> grp;
vector<vector<int>> decisionVector;

 
const int DOWN=1;
const int RIGHT=2;
const int LAST=3;
 
int decideEqual(int i, int j, vector<vector<int>> &down, vector<vector<int>> &curr){
    map<int,int> left, right;
    for(int I=M-1;I>=0;I--){
        left[down[j][I]]=I;
        right[curr[j+1][I]]=I;
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
 
int decide(int i, int j, vector<vector<int>> &down, vector<vector<int>> &curr){
    if(i>=N && j>=N) return LAST; // when on last index;
    if(i+1 < N && j+1 < N){
        // when both exist
        if(grp[i+1][j] == grp[i][j+1]){
            return RIGHT;
            return decideEqual(i, j, down, curr);
        }else{
            return grp[i+1][j] < grp[i][j+1] ? DOWN : RIGHT;
        }
    }else{ // only one exist return that one
        return i+1 < N ? DOWN: RIGHT;
    }
}

void build2()
{
    
}

string move()
{
    string ans = "";
    int i = 0, j = 0;
    while (!(i >= N || j >= N))
    {
        ans += inp[i][j];
        int decision = decisionVector[i][j];
        if (decision == LAST)
        {
            return ans;
        }
        if (decision == DOWN)
        {
            i += 1;
        }
        else
        {
            j += 1;
        }
    }
    return ans;
}

void solve()
{
    // Your solution code here
    cin >> N;
    inp.resize(N);
    decisionVector.resize(N, vector<int>(N));
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
    vector<vector<int>> down(N, vector<int>(M, MOD)), curr(N, vector<int>(M, MOD));

    //--------
    for (int j = N - 1, i = N - 1; j >= 0; j--)
    {
        down[j][grp[i][j]] = j + i;
        if (j + 1 < N)
        {
            for (int I = 0; I < M; I++)
            {
                down[j][I] = min(down[j][I], down[j + 1][I]);
            }
            decisionVector[i][j] = RIGHT;
        }
    }
// return;
    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            // i+1 will always exist in form of down;
            curr[j][grp[i][j]] = i + j;
            // for (int I = 0; I < M; I++)
            // {
            //     curr[j][I] = min(down[j][I], curr[j][I]); // compare with down
            //     if (j + 1 < N)
            //         curr[j][I] = min(curr[j + 1][I], curr[j][I]);
            // }

            // decisionVector[i][j] = decide(i, j, down, curr);
            down = curr;
            // curr.assign(N, vector<int>(M, MOD));
        }
    }
    // build2();
    // for (const auto &row : decisionVector)
    // {
    //     for (const auto &val : row)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << "\n";
    // }
    // cout<<move();
    cout<<"";
}

int main()
{
    fastio;

    // File I/O (local only)
    if (LOCAL_ENV)
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

    int t = 1;
    // cin>>t;
    while (t--)
    {

        {
            solve();
        }
    }

    return 0;
}