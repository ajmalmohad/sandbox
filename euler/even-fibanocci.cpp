#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll n,mod;
    mod = 4000000;
    ll first = 1;
    ll second = 2;
    ll third = first+second;
    ll sum = second;
    while(third <= mod){
        third = first+second;
        if(third%2==0) sum+=third;
        first = second;
        second = third;
    }
    cout<<sum<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
