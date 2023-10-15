#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    // freopen("promote.in", "r", stdin);
    // freopen("promote.out", "w", stdout);

    vector<pair<int, int>> participate;
    for (int i = 0; i < 4; i++){
        int a, b;
        cin>>a>>b;
        participate.push_back({a, b});
    }

    vector<int> ans;
    int previous = 0;
    for (int i = 3; i > 0; i--){
        int current = participate[i].second - participate[i].first + previous;
        ans.push_back(current);
        previous = current;
    }

    for (int i = 2; i >= 0; i--) cout<<ans[i]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}