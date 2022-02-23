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
    ll count = 0;
    while(n-(n%m) > 0){
        count += n-(n%m);
        n = (n%m) + n/m;
    }
    cout<<count+n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
