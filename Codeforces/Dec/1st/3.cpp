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



void solve() {
    // Your solution code here
   int n;cin>>n;
   vector<int> v(n), a(n), b(n), c(n), d(n);for(auto &i: v)cin>>i;
   
   auto ff=[&](auto func, vector<int> &a, int loopDirection){
    stack<pair<int,int>> st;
      for(int i=loopDirection?0:n-1;loopDirection? i<n: i>=0 ;loopDirection?i++:i--){
    if(st.empty()){
      a[i]=loopDirection?0:n-1;
    }else{
      while(!st.empty() && func(st.top().first, v[i])){
        st.pop();
      }
      if(st.empty()){
        a[i]=loopDirection?0:n-1;
      }else{
        a[i]=st.top().second;
      }
    }
    st.push({v[i], i});
   }
   };

   auto func1 = [](int a, int b){
    return a<b;
   };
   auto func2= [](int a, int b){
    return a>b;
   };
   ff(func1,a, 1);
   ff(func2, b, 1);
   ff(func1, c, 0);
   ff(func2, d, 0);
   for(int i=0;i<n;i++){
    if(max(b[i], d[i])-min(a[i],c[i])>=n-1){
      cout<<1;
    }else cout<<0;
    cout<<" ";
   }
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