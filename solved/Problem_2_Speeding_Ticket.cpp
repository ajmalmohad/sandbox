#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    int n, m;
    cin>>n>>m;
    int acc = 0;
    vector<int> limits(100+1, 0);
    for (int i = 0; i < n; i++){
        int dist, speed;
        cin>>dist>>speed;
        for (int j = acc+1; j <= acc+dist; j++) limits[j] = speed;
        acc += dist;
    }

    acc = 0;
    vector<int> bessie(100+1, 0);
    for (int i = 0; i < m; i++){
        int dist, speed;
        cin>>dist>>speed;
        for (int j = acc+1; j <= acc+dist; j++) bessie[j] = speed;
        acc += dist;
    }

    int maxm = 0;
    for (int i = 0; i <= 100; i++) {
        maxm = max(maxm, bessie[i] - limits[i]);
    }

    cout<<maxm<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}