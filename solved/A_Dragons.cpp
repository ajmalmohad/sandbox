#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll initialStrength, dragons;
    cin>>initialStrength>>dragons;

    vector<pair<ll,ll>> allDragons;
    for (int i = 0; i < dragons; i++){
        ll dragonStrength;
        ll perks;
        cin>>dragonStrength>>perks;
        allDragons.emplace_back(dragonStrength,perks);
    }

    sort(allDragons.begin(),allDragons.end());

    for (auto x : allDragons){
        if(initialStrength > x.first){
            initialStrength += x.second;
        }else{
            cout<<"NO\n";
            return;
        }
    }
    
    cout<<"YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
