#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    // freopen("cowsignal.in", "r", stdin);
    // freopen("cowsignal.out", "w", stdout);
    int n, m, k; 
    char temp;
    cin>>n>>m>>k;
    for (int i = 0; i < n; i++){
        string s;
        for (int j = 0; j < m; j++){
            cin>>temp;
            for (int x = 0; x < k; x++) s+=temp;
        }
        for (int x = 0; x < k; x++) cout<<s<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}