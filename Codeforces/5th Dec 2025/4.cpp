#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define int long long
#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

void solve1(){
  int n;cin>>n;
   int m;cin>>m;
   vector<int> a(n), b(m);
   for(auto &i: a)cin>>i;
   for(auto &i: b)cin>>i;
   reverse(a.begin(), a.end());
   reverse(b.begin(), b.end());
   multiset<int> mp;
   mp.insert(a.begin(), a.end());
   int magic=0, ans=0;
   for(int i=0, j=0;i<n;i++){
    auto it=mp.lower_bound(b[j]);
    
   }
}

void solve() {
    // Your solution code here
   int n;cin>>n;
   int m;cin>>m;
   vector<int> a(n), b(m);
   for(auto &i: a)cin>>i;
   for(auto &i: b)cin>>i;
   multiset<pair<int,int>> ms;
   for(int i=0;i<n;i++){
    ms.insert({a[i], i});
   }
   auto ms1=ms;
   int flag=0;
   int itr=0;
   int ans=0;
   int currPos=0;
int i=0, j=0;
   for(i=0;i<n;i++){
    if(a[i]>=b[j]){
      j++;
    }else break;
   }
   if(j==m){
    cout<<0; return;
   }else{
    // first flagged run;
    j++;
    ans=b[j];
    for(;i<n;i++){
    if(a[i]>=b[j]){
      j++;
    }else break;
   }
   }

   for(auto i: b){
    auto it=ms1.lower_bound(make_pair(i, 0));
    if(it==ms1.end() || n-((*it).second) < m-itr){ 
      if(flag==0) {flag=1; ans=i;}
      else {flag=2; break;}
    }else 
    ms1.erase(it);

    itr++;
   }
   if(flag==0){
    cout<<0;
   }else if(flag==1){
    cout<<ans;
   }else cout<<-1;
  }

int32_t main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

int t=1;
cin>>t;
    while(t--) {
        solve(); 
cout<<"\n";
    }

    
    return 0;
}