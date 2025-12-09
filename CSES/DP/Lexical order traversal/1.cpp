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

vector<string> inp;
vector<vector<int>> grp;
vector<vector<pair<int, int>>> parent;
vector<vector<int>> addedToList;
typedef pair<int, int> pi;
int N;
#define MP(a, b) make_pair(a, b)

void modifiedBFS()
{
    int i = 0, j = 0;
    map<int, list<pair<int, int>>> valuesAndTheirCoordinatesAsList;
    valuesAndTheirCoordinatesAsList[grp[i][j]].push_back({i, j});
    while (!valuesAndTheirCoordinatesAsList.empty())
    {
        // we only care about list with lowest value key, because only those values will be lexically shortest. Others are not possible to be part of solution. 
        list possibleSolutionsInCurrentLevel = (*valuesAndTheirCoordinatesAsList.begin()).second; // getting the list with min value in the current level 
        
        valuesAndTheirCoordinatesAsList.clear(); // clearing the level after getting the min list( only possible solutions for that level)
        
        for (auto [x, y] : possibleSolutionsInCurrentLevel)
        { // what ever values will be added are for the next level only since previous level data is removed
            if (x + 1 < N && !addedToList[x + 1][y]) // check right possibility
            {
                valuesAndTheirCoordinatesAsList[grp[x + 1][y]].emplace_back(MP(x + 1, y));
                parent[x + 1][y] = MP(x, y);
                addedToList[x + 1][y] = 1;
            }
            if (y + 1 < N && !addedToList[x][y + 1]) // check down possibility
            {
                valuesAndTheirCoordinatesAsList[grp[x][y + 1]].emplace_back(MP(x, y + 1));
                parent[x][y + 1] = MP(x, y);
                addedToList[x][y + 1] = 1;
            }
        }
    }
}

string traverse()
{ // simply traversing the parent from n-1, n-1 to 0, 0
    string ans;
    int x = N - 1, y = N - 1;
    while (!(x == -1 && y == -1))
    {
        ans += inp[x][y];
        auto [newX, newY] = parent[x][y];
        x = newX;
        y = newY;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve()
{
    // Your solution code here
    cin >> N;
    parent.assign(N, vector<pair<int, int>>(N, MP(-1, -1)));
    addedToList.resize(N, vector<int>(N, 0));
    inp.resize(N);
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

    modifiedBFS();
    auto ans = traverse();
    cout << ans;
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
        solve();
    }

    return 0;
}