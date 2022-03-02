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
    if(n<26){ cout<<"NO\n"; return; }
    string a;
    cin>>a;
    unordered_map<char, bool> record;
    ll count = 0;
    for (int i = 0; i < n; i++){
        if(!record[tolower(a[i])]){
            record[tolower(a[i])] = true;
            count++;
        } 
    }
    if(count>=26) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
