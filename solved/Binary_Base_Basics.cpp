#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

ll counts = 0;

void palindrome(string s, ll i){
    if(i>=s.size()/2) return;
    if(s[i] != s[s.size()-i-1]) counts++;
    palindrome(s, i+1);
}


void solve(){
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    string s;
    cin>>s;
    palindrome(s, 0);

    bool odd = s.size()%2!=0 ? true : false;

    k -= counts;

    counts=0;

    if(k < 0){
        cout<<"NO\n";
        return;
    }else if( k == 0){
        cout<<"YES\n";
        return;
    }else if(odd){
        cout<<"YES\n";
        return;
    }else if(k%2 == 0){
        cout<<"YES\n";
        return;
    }else{
        cout<<"NO\n";
        return;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
