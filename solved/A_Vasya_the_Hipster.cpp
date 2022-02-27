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

    ll count=0;
    while(a>0 && b>0){
        a--;
        b--;
        count++;
    }
    cout<<count<<' ';
    count = 0;

    a = max(a,b);
    while(a>1){
        a-=2;
        count++;
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
