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

    ll count = 0;
    
    count += n/100;
    n = n%100;
    count += n/20;
    n = n%20;
    count += n/10;
    n = n%10;
    count += n/5;
    n = n%5;
    cout<<count+n<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
