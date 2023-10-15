#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

ll abso(ll x){
    if(x < 0){
        return -x;
    }else{
        return x;
    }
}

void solve(){
    ll n, total = 0;
    cin>>n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin>>nums[i];
    sort(nums.begin(), nums.end());

    ll median = nums[n/2];
    for(ll x: nums){
        total += abso(x - median);
    }

    cout<<total<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}