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
   int a,b,c;
   cin>>a>>b>>c;
   int vacencies=1, height=0;
   while (1)
   {
    if(a>0){
      int consumedA=0;
      if(a>vacencies){
        a-=vacencies;
        consumedA=vacencies;}
      else{
        a=0;
        vacencies;
        consumedA=a;
      }
      vacencies+=consumedA*2;
      height++;
    }else{
      if(b>0){

      }
    }
   }
   

}

void solve2(){
  int a,b,c;
   cin>>a>>b>>c;
   int height=a==0?0:floor(log2(a*1.0+1.0));
   int leftOver=0;
   int places=exp2(height);
   if(exp2(height*1.0)<=(a*1.0)){
    leftOver= exp2((height)*1.0)-((a*1.0)-exp2((height-1)*1.0));
    places=((a*1.0)-exp2((height-1)*1.0))*2+leftOver;
    height++;
   }
   if(b>=leftOver){
    b-=leftOver;
   }
   if(b>0){
    int vac=exp2(height*1.0);
    int layers=ceil(b/vac);
    height+=layers;
   }

   if(c!=places){
    cout<<(-1);
   }else{
    cout<<height;
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
        solve2(); 
cout<<"\n";
    }

    
    return 0;
}