#include<iostream>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    ll count = 0;
    for (int i = 0; i < n; i++){
        ll members;
        ll capacity;
        cin>>members>>capacity;
        if(members <= capacity-2){
            count++;
        }
    }

    cout<<count<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) solve();
    return 0;
}
