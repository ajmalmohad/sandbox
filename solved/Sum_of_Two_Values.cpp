#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    ll n, k, minm = 1e9+7;
    cin>>n>>k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        minm = min(minm, arr[i]);
    }

    if(k <= minm){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    unordered_map<ll, ll>  record;
    for (int i = 0; i < n; i++) {
        if(record[arr[i]]){
            cout<<record[arr[i]]<<" "<<i+1<<'\n';
            return;
        }else if(arr[i] <= k){
            record[k - arr[i]] = i+1;
        }
    }

    cout<<"IMPOSSIBLE\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n = 1;
    while(n--) solve();
}