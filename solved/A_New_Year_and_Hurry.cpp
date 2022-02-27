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
    ll time = 240-k;
    if(time<0) cout<<0<<'\n';
    int i=1;
    for (i = 1; i <= n; i++){
        time -= i*5;
        if(time<0) break;
    }
    cout<<i-1<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
