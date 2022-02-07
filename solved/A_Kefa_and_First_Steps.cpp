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

    ll temp;
    cin>>temp;
    ll count = 1;
    ll maxcount = 1;
    ll prev = temp;
    for (int i = 0; i < n-1; i++){
        cin>>temp;
        if(temp>=prev) count++;
        else count=1;
        maxcount = max(count, maxcount);
        prev = temp;
    }
    cout<<maxcount<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
