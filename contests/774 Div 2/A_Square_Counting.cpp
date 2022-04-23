#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll n,s;
    cin>>n>>s;
    if(n*n > s){
        cout<<0<<'\n';
        return;
    }else{
        cout<<s/(n*n)<<'\n';
        return;
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
