#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll k,l,m,n,total;
    cin>>k>>l>>m>>n>>total;

    int counts = 0;
    for (int i = 1; i <= total; i++){
        if(i%k==0 || i%l==0 || i%m==0 || i%n==0) counts++;
    }
    cout<<counts<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
