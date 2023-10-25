#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    ll n, temp;
    cin>>n;
    multiset<ll> towers;
    for (ll i = 0; i < n; i++) {
        cin>>temp;
        auto idx = towers.upper_bound(temp);
        if(idx == towers.end()){
            towers.insert(temp);
        }else{
            towers.erase(idx);
            towers.insert(temp);
        }
    }

    cout<<towers.size()<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}