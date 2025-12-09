#include <bits/stdc++.h>
using namespace std;


int main(){
    // freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     freopen("error.txt", "w", stderr);
int n,m;
cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> posIndex(n+1);
   for(int i=0;i<n;i++ ){
        posIndex[arr[i]]=i;
    }
    int pre=arr[0],count=1;
    for(int i=2;i<=n;i++){
        if(posIndex[i-1] > posIndex[i]){
            count++;
        }
    }
    while(m--){
        int a,b;cin>>a>>b;
        a--;b--; // 0-based indexing
        int val1=arr[a],val2=arr[b];
        set<int> change;
        change.insert(val1);
        change.insert(val1+1);
        change.insert(val2);
        change.insert(val2+1);
        for(int i: change){
            if(i>0 && i<=n){
                count-=posIndex[i]<posIndex[i-1];
            }
        }
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;

        temp=posIndex[val1];
        posIndex[val1]=posIndex[val2];
        posIndex[val2]=temp;

        for(int i: change){
            if(i>0 && i<=n){
                count+=posIndex[i]<posIndex[i-1];
            }
        }
        cout<<count<<endl;
    }
}