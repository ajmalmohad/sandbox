#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll n,m;
    cin>>n>>m;

    string full,first,last;
    for (int i = 0; i < m; i++) full+='#';

    first+="#";
    for (int i = 1; i < m; i++) first+='.';

    for (int i = 1; i < m; i++) last+='.';
    last+="#";

    bool toggle = true;
    for (int i = 0; i < n; i++){
        if(i%2==0) cout<<full<<'\n';
        else{
            if(toggle){ cout<<last<<'\n'; toggle = !toggle; }
            else{ cout<<first<<'\n'; toggle = !toggle; }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
