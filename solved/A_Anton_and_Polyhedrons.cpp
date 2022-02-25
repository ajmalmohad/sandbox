#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;


void solve(){
    unordered_map<string, int> record;
    record["Tetrahedron"] = 4;
    record["Cube"] = 6;
    record["Octahedron"] = 8;
    record["Dodecahedron"] = 12;
    record["Icosahedron"] = 20;

    ll n, count=0;
    cin>>n;
    for (int i = 0; i < n; i++){
        string s;
        cin>>s;
        count+=record[s];
    }
    cout<<count<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
