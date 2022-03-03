#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll a,b;
    cin>>a>>b;
    ll diff = abs(a-b);
    ll count=0;
    for (int i = 10; i >=1; i--){
        count+=diff/i;
        diff=diff%i;
    }
    cout<<count<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
