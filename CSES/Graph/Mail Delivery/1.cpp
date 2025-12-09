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

void solve()
{
    // Your solution code here
    int n, m;
    cin >> n >> m;
    vector<int> xorEdges;
    vector<int> vis(m + 1, 0), deg(n + 1, 0);
    vector<vector<int>> grp(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        xorEdges.push_back(a ^ b);
        deg[a]++;
        deg[b]++;
        grp[a].push_back(i);
        grp[b].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] & 1)
        {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    vector<int> edgeVis(xorEdges.size());
    vector<int> ans;
    stack<int> st;
    st.push(1);
    while (!st.empty())
    {
        auto top = st.top();
        if (deg[top] == 0)
        {
            st.pop();
            ans.push_back(top);
        }
        else
        {
            for (int i = grp[top].size() - 1; i >= 0; i--)
            {
                int connectedEdge = grp[top].back();
                if (!edgeVis[connectedEdge])
                {
                    int connectedVertex = xorEdges[connectedEdge] ^ top;
                    st.push(connectedVertex);
                    edgeVis[connectedEdge] = 1;
                    deg[top]--;
                    deg[connectedVertex]--;
                    break;
                }
                else
                {
                    grp[top].pop_back(); // required for optimization
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    { // the graph might be fragmented; unconnected
        if (!edgeVis[i])
        {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    for (auto i : ans)
        cout << i << " ";
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