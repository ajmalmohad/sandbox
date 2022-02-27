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

    ll a=0;
    ll b=0;
    while(n--){
        ll c,d;
        cin>>c>>d;
        if(c>d) a++;
        else if(d>c) b++;
    }

    if(a>b) cout<<"Mishka";
    else if(b>a) cout<<"Chris";
    else cout<<"Friendship is magic!^^";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
