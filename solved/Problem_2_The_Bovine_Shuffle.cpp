#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    freopen("shuffle.in","r", stdin);
    freopen("shuffle.out","w", stdin);
    int n;
    cin>>n;
    vector<int> shuffles(n+1);
    vector<int> cows(n+1);
    for (int i = 1; i <= n; i++) {
        int temp;
        cin>>temp;
        shuffles[temp] = i;
    }
    for (int i = 1; i <= n; i++) cin>>cows[i];

    for (int i = 0; i < 3; i++) {
        vector<int> orders(n+1);
        for (int j = 1; j <= n; j++) {
            orders[shuffles[j]] = cows[j];
        }
        cows = orders;
    }

    for (int i = 1; i <= n; i++) {
        cout<<cows[i]<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}