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
        record.push_back({start, 1});
        record.push_back({end+1, -1});
    }
    sort(record.begin(), record.end());
    ll maxm = 0;
    ll acc = 0;
    for (int i = 0; i < record.size(); i++){
        acc += record[i].second;
        maxm = max(maxm, acc);
    }

    cout<<maxm<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n = 1;
    while(n--) solve();
}