#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());

    ll total = 0;
    for (ll i = 0; i < n; i++) {
        if(total + 1 < arr[i]) break;
        else total += arr[i];
    }

    cout<<total+1<<"\n";
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}