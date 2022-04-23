#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    ll count = 0;
    ll sum = 0;
    std::vector<ll> arr;
    arr.reserve(n);
    for (int i = 0; i < n; i++){
        ll current;
        cin>>current;
        sum+=current;
        arr.push_back(current);
    }
    sort(arr.begin(),arr.end());

    for (int i = 0; i < n/2; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
