#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

bool oddivisor(ll n){
    while(n>0){
        if((n/2)*2 == n){
            if(n==1) return true;
            n/=2;
        }else{
            return false;
        }
    }
    return false;
}

void solve(){
    ll n;
    cin>>n;
    string ans;
    if(n%2==1) ans = "YES";
    else if(oddivisor(n)) ans = "YES";
    else ans = "NO";
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
