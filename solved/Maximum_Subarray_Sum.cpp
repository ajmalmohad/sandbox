#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    ll n, maxm = -2e9, total = 0;
    cin>>n;
    vector<ll> nums(n);
    for (ll i = 0; i < n; i++) {
        cin>>nums[i];
        total = max(total + nums[i], nums[i]);
        maxm = max(maxm, total);
    }
    
    cout<<maxm<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}