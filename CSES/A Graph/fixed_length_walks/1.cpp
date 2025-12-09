#include <bits/stdc++.h>
using namespace std;
// accepted solution

#define LOCAL_ENV false

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

const int MOD = 1e9 + 7;

void solve()
{
    int numberOfNodes, numberOfEdges, numberOfQueries;
    cin >> numberOfNodes >> numberOfEdges >> numberOfQueries;
    vector<vector<int>> graph(numberOfNodes + 1, vector<int>());
    vector<vector<int>> oddMinDistanceBetween(numberOfNodes + 1, vector<int>(numberOfNodes + 1, MOD));  // keeps track of all odd values
    vector<vector<int>> evenMinDistanceBetween(numberOfNodes + 1, vector<int>(numberOfNodes + 1, MOD)); // track even values
    for (int i = 0; i < numberOfEdges; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int originNode = 1; originNode <= numberOfNodes; originNode++) // iterate over all nodes; idea is get min values between each pair of nodes. so doing BFS from each node ̰
    {                                               
        evenMinDistanceBetween[originNode][originNode] = 0; // intial even value from each node to self is 0

        // ---- starting BFS -----
        queue<int> bfsQueue;
        bfsQueue.push(originNode);
        while (!bfsQueue.empty())
        {
            int currentNode = bfsQueue.front();
            bfsQueue.pop();
            
            for (int neighbourNode : graph[currentNode])
            {
                bool isUpdated = false; // keeping track of any node value updated; 
                if (oddMinDistanceBetween[originNode][currentNode] + 1 < evenMinDistanceBetween[originNode][neighbourNode])
                {
                    evenMinDistanceBetween[originNode][neighbourNode] = oddMinDistanceBetween[originNode][currentNode] + 1;
                    // evenMinDistanceBetween[neighbourNode][originNode] = evenMinDistanceBetween[originNode][neighbourNode]; // --Not working...why? || idea: can be further optimised by using mirror property of the matrix
                    // found reasong for above... this distance was calculated from one origin to this node, however This may not be the min distance from neighbourNode to the origin. For that I need to check with BFS from this neighbour node.
                    isUpdated = true;
                }
                if (evenMinDistanceBetween[originNode][currentNode] + 1 < oddMinDistanceBetween[originNode][neighbourNode])
                {
                    oddMinDistanceBetween[originNode][neighbourNode] = evenMinDistanceBetween[originNode][currentNode] + 1;
                    // oddMinDistanceBetween[neighbourNode][originNode] = oddMinDistanceBetween[originNode][neighbourNode]; //--Not working...why? || idea: can be further optimised by using mirror property of the matrix
                    isUpdated = true;
                }

                if (isUpdated) // if updated only then explore all the neighbours of the said node (ie to add this node to queue)
                {
                    bfsQueue.push(neighbourNode);
                }
            }
        }
    }
    vector<string> ans;
    while (numberOfQueries--)
    {
        int nodeA, nodeB, exactSteps;
        cin >> nodeA >> nodeB >> exactSteps;
        int miniumDistanceWithParity = MOD;

        // we get same parity min distance between nodes a and b
        if ((exactSteps & 1) == 1)
        {
            miniumDistanceWithParity = oddMinDistanceBetween[nodeA][nodeB];
        }
        else
        {
            miniumDistanceWithParity = evenMinDistanceBetween[nodeA][nodeB];
        }

        if (miniumDistanceWithParity == MOD)
        { // in case where there was no update; meaning node is not reachable
            ans.push_back("NO");
        }
        else
        {
            if (exactSteps >= miniumDistanceWithParity)
            { // the primary idea is if I can read a place in say x even steps then I can keep looping on the last node[ So effectively I can reach the last node in x+2, x+4... steps]... same logic for odd
                ans.push_back("YES");
            }
            else
            {
                ans.push_back("NO");
            }
        }
    }

    for (auto i : ans)
    {
        cout << i << "\n";
    }
}

int main()
{
    fastio;
     if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}