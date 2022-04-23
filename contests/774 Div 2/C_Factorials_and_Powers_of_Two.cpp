#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

ll factorial[15] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200};
void solve(){
    ll n;
    cin>>n;
    ll diff = n;
    while(diff!=0){
        ll count=-1;
        for (int i = 0; i < 15; i++) if(n>factorial[i]) count++;
        diff = n-factorial[count];
        diff = max((ll)(n - pow(2,(ll)log2(n))),diff);
        cout<<diff;
        diff=0;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
