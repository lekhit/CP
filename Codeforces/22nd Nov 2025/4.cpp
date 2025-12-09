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

map<int, string> mp;
vector<pair<int,string>> minPal;

int convertToMin(string s){
  string hr=s.substr(0, 2);
  string mi=s.substr(2, 2);
  int h=stoi(hr), m=stoi(mi);
  int mm=h*60+m;
  return mm;
}
void getAllPal(){
  
  for(int i=0;i<24;i++){
    string s="";
    if(i<10){
      s+='0';
    }
    s+=to_string(i);
    for(int j=0;j<60;j++){
      string temp="";
      if(j<10){
        temp+='0';
      }
      temp+=to_string(j);
      auto s1=s+temp;
      auto s2=s1;
    reverse(s1.begin(), s1.end());
    if(s1==s2){ 
      cout<<s1<<endl; cout<<(convertToMin(s1))<<endl;
      
      mp[convertToMin(s1)]=s1;}
    }
    // cout<<s1<<" "<<s<<"\n";
  }
}

void check(int gMin, int x){
  
}

void solve() {
    // Your solution code here
    int MOD=24*60;
    string s; int x;cin>>s>>x;
    string hr=s.substr(0, 2);
    string mi=s.substr(3, 2);
    s=hr+mi;
    int gMin=convertToMin(s);
    // (gMin-x+MOD)%x
    int c=0;
    for(auto [minutes, st]: minPal){
      if(((minutes-gMin+MOD)%x)==0){
        c++;
      }
    }
    cout<<c;
}
/*
(nx+c)%MOD 
(mi-c+MOD)%x == 0
*/
int32_t main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }
getAllPal();
for(auto i: mp) minPal.push_back(i);
int t=1;
cin>>t;
    while(t--) {
        solve(); 
cout<<"\n";
    }

    
    return 0;
}