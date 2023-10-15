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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    

    // Code Here
    vector<ll> b = a;
    sort(b.begin(), b.end());

    unordered_map<int, vector<int>> record;
    for (int i = 0; i < n; i++) {
        record[b[i]].push_back(n - i);
    }
    
    for (int i = 0; i < n; i++){
        int last = record[a[i]].size() - 1;
        cout<<record[a[i]][last]<<" ";
        record[a[i]].pop_back();
    }


    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    while(n--) solve();
}