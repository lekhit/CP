#include <bits/stdc++.h>
using namespace std;
 
class person{
    public:
    int id;
    int start;
    int end;
    person(int i, int s, int e){
        id=i;
        start=s;
        end=e;
    }
    void print(){
        printf("person: id:%d start:%d end:%d\n", id, start, end);
    }
};
 
int main(){
    //   freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    int n; cin>>n;
    vector<person> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(person(i, a, b));
    }
    sort(v.begin(), v.end(), [](person a, person b){
        if(a.end == b.end){
            return a.start < b.start;
        }
        return a.end < b.end;
    });
    multiset<pair<int,int>> ms;
    vector<int> allocation(n);
    int ans=0;
    for(auto entry: v){
        // cout<<"-----"<<endl;
        int p=entry.start;
        int q=entry.end;
        auto it = ms.lower_bound(make_pair(p,0)); // finding the vacated room
        // entry.print();
        // cout<<"it: "<<(*it).first<<" "<<(*it).second<<endl;
        pair<int,int> newRoom;
        if(it != ms.begin()){
            // this means it is empty or no room can be empted 
            // so create new room 
            --it;
            int oldRoom=(*it).second;
            newRoom=make_pair(q, oldRoom);
            ms.erase(it);
        }else{
            ++ans;
            newRoom=make_pair(q, ans);
        }
        allocation[entry.id]=newRoom.second;
        ms.insert(newRoom);
        // for(auto i: ms){cout<<"entry: "<<i.first<<" "<<i.second<<endl;}
    }
    cout<<ans<<endl;
    for(auto i: allocation){
        cout<<i<<" ";
    }
 
 
    return 0;
}
