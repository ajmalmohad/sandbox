#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    ll a = n-3;
    ll b = 2;
    while(__gcd(a,b) != 1){
        a--;
        b++;
    }
    cout<<a<<' '<<b<<' '<<1<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
