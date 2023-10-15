#include<iostream>
#include<string>
using namespace std;
typedef long long ll;

const ll modulo = 1000000007;

void solve(){
    ll n,k,m;
    cin>>n>>k>>m;
    string s;
    cin>>s;
    string newone;
    while(m--){
        for (int i = 0; i < s.size(); i++){
            int temp = s[i] - '0';
            ll ans = temp*k;
            newone += to_string(ans);
        }
        s = newone;
        newone = "";
    }

    k = s.size()%modulo;
    cout<<k<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}