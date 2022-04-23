#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int binarySearch(ll l, ll r, ll x, ll mod){
    if (r >= l) {
        ll mid = (l + (r - l) / 2);
        if (mid%mod==x)
            return mid;
        if (mid%mod > x)
            return binarySearch(l, mid - 1, x, mod);
        return binarySearch(mid + 1, r, x, mod);
    }
    return -1;
}

void solve(){
    ll left, right, mod, res;
    cin>>left>>right>>mod;
    res = LONG_MIN;
    if(mod > right){
        res = right/mod + right%mod;
    }else if(right%mod==0){
        if((right-1)>=left) right--;
        res = right/mod + right%mod;
    }else{
        cout<<binarySearch(10,12,mod-1, mod)<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
