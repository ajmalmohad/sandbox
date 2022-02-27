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

    ll count=0;
    ll current;
    cin>>current;
    ll minimum = current;
    ll maximum = current;
    for (int i = 1; i < n; i++){
        cin>>current;
        if(current > maximum) count++;
        if(current < minimum) count++;
        minimum = min(minimum, current);
        maximum = max(maximum, current);
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
