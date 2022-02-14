#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> arr;
    arr.reserve(m);
    for (int i = 0; i < m; i++){
        ll temp;
        cin>>temp;
        arr.push_back(temp);
    }

    sort(arr.begin(),arr.end());

    ll minim = arr[n-1]-arr[0];
    for (int i = 0; i <= m-n; i++){
        minim = min(minim, arr[i+n-1]-arr[i]);
    }
    
    cout<<minim<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
