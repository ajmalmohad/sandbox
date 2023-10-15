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
    vector<pair<ll, ll>> record;
    for (int i = 0; i < n; i++){
        ll start, end;
        cin>>start>>end;
        record.push_back({end, start});
    }
    sort(record.begin(), record.end());
    
    ll count = 0;
    ll prevend = 0;
    for (auto item: record){
        if(item.second >= prevend){
            count++;
            prevend = item.first;
        }
    }

    cout<<count<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n = 1;
    while(n--) solve();
}