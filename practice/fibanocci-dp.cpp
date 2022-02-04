#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
typedef unsigned long long ll;

void solve(){
    ll n;
    cin>>n;

    ll first = 0;
    ll second = 1;
    ll third;
    if(n<2) { cout<<"1"<<'\n'; return; }
    for (ll i = 2; i <= n; i++){
        third = first+second;
        first = second;
        second = third;
    }
    cout<<third;   
}

int main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}
