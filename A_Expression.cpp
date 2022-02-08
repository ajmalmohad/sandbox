#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans = max(a+b+c,a*b*c);      
    ans = max(ans,a*(b+c));      
    ans = max(ans,a*b+c);      
    ans = max(ans,a+b*c);      
    ans = max(ans,(a+b)*c);   
    cout<<ans<<'\n';   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
