#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    unordered_map<ll,ll> first;
    vector<ll> second;
    first.reserve(n);
    second.reserve(n);
    for (int i = 0; i < n; i++){
        ll a, b;
        cin>>a>>b;
        first[a]++;
        second.push_back(b);
    }

    ll count = 0;
    for (auto game : second){
        if(first[game]) count+=first[game];
    }

    cout<<count<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
