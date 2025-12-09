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


string reverse(string ss){
    string s=ss;
    for(int i=0;i<s.size()/2;i++){
        swap(s[i],s[s.size()-1-i]);
    }
    // cout<<s<<" "<<ss<<endl;
    return s;
}

string addOne(string s){
    string ans="";
    s=reverse(s);
    int carry=1;
    for(auto i:s){
        int num=i-'0';
        if(num  + carry > 9){
            carry=1;
            ans+= (((num+carry)%10)+'0');
        }else{
             ans+= (((num+carry)%10)+'0');
             carry=0;
        }
        // if(carry==0) break;
    }
    if(carry==1){
        ans+='1';
    }
    return reverse(ans);
}

string rpal(string firstHalf){
    int n=firstHalf.size();
    string tempReverse=reverse(firstHalf);
    string ans=firstHalf;
        for(int i=0;i<n;i++){
            if(i==0 && (n&1)){
                continue;
            }
            ans+=tempReverse[i];
        }
        return ans;
}




string solve(){
    string s;cin>>s;
    int n=s.size();
    if(n==1) return "11";
    int mid=n/2;
    string cfirstHalf=reverse(s.substr(0,mid));
    if(n&1){mid++;}
    string firstHalf=s.substr(0, mid);
    string secondHalf=s.substr(mid);
    cout<<s<<endl;
    if(secondHalf < cfirstHalf){
        return firstHalf+cfirstHalf;
    }else{
        return rpal(addOne(firstHalf));
    }
    // cout<<(secondHalf < cfirstHalf)<<endl;

    // cout<<addOne(firstHalf)<<endl;
    // cout<<firstHalf<<endl;
    // cout<<secondHalf<<endl;
    return s;
}
int main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

    cout<<solve();
    
    return 0;
}