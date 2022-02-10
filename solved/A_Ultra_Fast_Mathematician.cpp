#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    string a,b;
    cin>>a>>b;
    for (int i = 0; i < a.size(); i++){
        cout<<(a[i]^b[i]);
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
