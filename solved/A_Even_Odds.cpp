#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll n,k;
    cin>>n>>k;

    ll odds = 0;
    ll evens = 0;
    if(n%2==0){
        odds=n/2;
        evens=n/2;
    }else{
        odds=(n/2)+1;
        evens=n/2;
    }

    ll ans;
    if(k<=odds){
        ans = 1+(k-1)*2;
    }else{
        ans = 2+(k-odds-1)*2;
    }

    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
