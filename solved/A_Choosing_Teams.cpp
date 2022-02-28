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
    k = 5-k;
    ll count = 0;
    for (int i = 0; i < n; i++){
        ll current;
        cin>>current;
        if(current <= k) count++;
    }
    cout<<count/3<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
