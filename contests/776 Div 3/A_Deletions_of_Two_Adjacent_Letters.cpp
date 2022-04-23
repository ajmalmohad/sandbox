#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    string n;
    cin>>n;
    char s;
    cin>>s;
    ll left=0;
    for (int i = 0; i < n.length(); i++){
        if(n[i] != s){ left++; }
        else if(left%2==0) break;
        else left++;
    }
    if(left%2==0) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
