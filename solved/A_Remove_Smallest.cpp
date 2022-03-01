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
    vector<ll> all;
    all.reserve(n);
    for (int i = 0; i < n; i++){
        ll current;
        cin>>current;
        all.push_back(current);
    }
    
    sort(all.begin(),all.end());
    for(int i=0; i<n-1; i++) if((all[i+1]-all[i])>1){ cout<<"NO\n"; return; }
    cout<<"YES\n";
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("io/input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
