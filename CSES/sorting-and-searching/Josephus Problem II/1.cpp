#include <bits/stdc++.h>
using namespace std;
//accepted solution

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

void solve(){
    int N,K;cin>>N>>K;
    int root=sqrt(N);
    if(root*root < N) root++;
    vector<vector<int>> arr;
    vector<int> temp;
    for(int i=1;i<=N;i++){
        temp.push_back(i);
        if(i%root == 0){
            arr.push_back(temp);
            temp.clear();
        }
    }
    if(temp.size()>0){
        arr.push_back(temp);
    }
    int row=0,col=0,elementsToSkip=K;
    vector<int> ans;
    for(int i=0;i<N;i++){
        elementsToSkip=(K%(N-i));
        while(elementsToSkip){
            if(col+elementsToSkip < arr[row].size()){
                // if the element is present in current row 
                col+=elementsToSkip;
                elementsToSkip=0;
            }else{
                // the element is out of present row but col can have some value eg: 1 2 3 4 5 say col was on 2 ie col=1 the skipped elements = total(5)- col(1) ==> skipped elemets are 2 3 4 5
                // here I am only removing contribution from the present row 
                int totalElementsInRow=arr[row].size();
                int contributionFromPreviousValueOfCol=col;
                elementsToSkip-=(totalElementsInRow-contributionFromPreviousValueOfCol);
                col=0;
                row=(row+1)%arr.size();
            }
        } //elementsToSkip is zero here meaning row,col is at place where the element is
        ans.push_back(arr[row][col]);
        // remove this element
        if(col < arr[row].size())
            {
                arr[row].erase(arr[row].begin()+col);// remove element
                if(arr[row].size()==0){ // if entire row is empty remove the row as well
                    arr.erase(arr.begin()+row);
                    if(row==arr.size()) row=0; // if the removed row was the last one then we are taking [row] back to zero
                }
                // row<arr.size() check was needed because previously we deleted row. so arr[row] will have problems if [row] itself does not exist (happens when i=N-1 we are removing the last row and then accessing that row itself with arr[row]).
                if(row<arr.size() && arr[row].size()==col) {// if we removed the last element of the row then we must move to next
                    row=(row+1)%arr.size(); // move to next row
                    col=0;  // start from zero of the next row
                }
                
            }
        // if entire row is empty the remove the row as well
        
    }
    for(auto i:ans) cout<<i<<" ";

}

int main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

    solve();
    
    return 0;
}