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


const int ADD=1, REMOVE=2, REPLACE=3, NO_CHANGE=4;

int getCostOfReplacement(char formChar, char toChar){
    // for now it's just 1 
    // but keeping for customisation
    return 1;
}

int getCostOfRemoval(char charToRemove){
    // this is the cost associated to remove a character 'from' string
    return 1;
}

int getCostOfAddition(char charToAdd){
    // this is cost associated with addition of char 'to' string
    return 1;
}

int getCostOfNoChange(char ch){
    return 0;
}

pair<int,int> getParent(int decision, int i, int j){
    switch (decision)
    {
    case ADD:
        return {i, j-1};
    case REMOVE:
        return {i-1, j};
    case REPLACE:
        return {i-1, j-1};
    }
}

void solve() {
    // Your solution code here
   string from, to;
   cin>>from>>to;
   // adding empty character to the strings 
    from=' '+from;
    to=' '+to; 
   int costOfReplacement=1, costOfAdding=1, costOfRemoval=1, costOfNoChange=0;
   
   int n=from.size(), m=to.size();
    vector<vector<int>> dp(n, vector<int>(m, 0)), decision(n, vector<int>(m,0)); // can be further optimised to pre and curr array
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m));

    for(int i=1;i<m;i++){
        dp[0][i]=dp[0][i-1]+costOfAdding;
        decision[0][i]=ADD;
        parent[0][i]={0,i-1};
    }
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+costOfRemoval; // here we are converting from string to empty string
        decision[i][0]=REMOVE;
        parent[i][0]={i-1, 0};
    }
    
    // iterating from 1, since string actually starts from '1' after adding ' ' empty character
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(from[i] == to[j]){
                dp[i][j]=dp[i-1][j-1]+getCostOfNoChange(from[i]);
                decision[i][j]=NO_CHANGE;
                parent[i][j]={i-1, j-1};
            }else{
            int costAfterReplacement = dp[i-1][j-1] + getCostOfReplacement(from[i], to[j]);
            int costAfterRemoval = dp[i-1][j] + getCostOfRemoval(from[i]);
            int costAfterAddition = dp[i][j-1] + getCostOfAddition(to[j]);
            auto minElement = min(make_pair(costAfterAddition, ADD), 
                                    min(make_pair(costAfterRemoval, REMOVE), 
                                    make_pair(costAfterReplacement, REPLACE)));
            decision[i][j]=minElement.second;
            dp[i][j]=minElement.first;
            parent[i][j]=getParent(decision[i][j], i, j);
            }
        }
    }
    cout<<dp[n-1][m-1]<<"\n";

    // print the decision path
    // int i=n-1, j=m-1;
    // while(i!=0 && j!=0){
    //     cout<<decision[i][j]<<" ";
    //     auto [tI, tJ]=parent[i][j];
    //     i=tI;
    //     j=tJ;
    // }
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