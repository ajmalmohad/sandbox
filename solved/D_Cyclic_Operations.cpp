#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    ll n, k;
    cin>>n>>k;
    vector<ll> b(n+1, 0);

    for (ll i = 1; i <= n; i++) cin>>b[i];

    if(k == 1){
        for (int i = 1; i <= n; i++){
            if(b[i] != i){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
        return;
    }

    queue<ll> que;
    que.push(1);
    unordered_map<ll, bool> visited;
    visited[1] = true;
    while(que.size()){
        int current = que.front();
        que.pop();
        if(!visited[b[current]]){
            visited[b[current]] = true;
            que.push(b[current]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    while(n--) solve();
}