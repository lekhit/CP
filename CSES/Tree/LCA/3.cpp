#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int LogN = 17;

vector<int> tree[N];
int level[N];
vector<vector<int>> sparse(N, vector<int>(LogN, -1));

void dfs(int parent, int node, int position)
{
   sparse[node][0] = parent;
   level[node] = position;
   for (int i : tree[node])
   {
       if (i == parent)
           continue;
       dfs(node, i, position + 1);
   }
}

int finfParent(int nodeA, int nodeB) {
   if(level[nodeB]>level[nodeA]){
       swap(nodeA, nodeB);
   }
   int diff= level[nodeA]-level[nodeB];
   int j=0;
   while(diff>0) {
       if(diff &1){
           nodeA=sparse[nodeA][j];
       }
       j++;
       diff=diff>>1;
   }
   if(nodeA==nodeB) return nodeA;
   for(int i=16;i>=0;--i){
       if(sparse[nodeA][i]==sparse[nodeB][i]){
           continue;
       }
       nodeA=sparse[nodeA][i];
       nodeB=sparse[nodeB][i];
   }
   return sparse[nodeA][0];
}

void solve()
{
   int n, q;
   cin >> n >> q;

   for (int i = 0; i < n - 1; i++)
   {
       int a, b;
       cin >> a >> b;
       tree[a].push_back(b);
       tree[b].push_back(a);
   }
   // levels obtained
   dfs(-1, 1, 0);
   // sparse[i][j]=0 means  no parent exists
   for(int j=1;j<=LogN;++j){
       for(int i=1;i<=n;++i){
           if(sparse[i][j-1]!=-1){
               sparse[i][j]=sparse[sparse[i][j-1]][j-1];
           }
       }
   }
   // cout<<"x"<<endl;
   // take queries
   while (q--)
   {
       int a, b;
       cin >> a >> b;
       int superParent = finfParent(a, b);
       int dist = level[a] + level[b] - (2 * (level[superParent]));
       cout << dist << endl;
   }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   solve();
   return 0;
}