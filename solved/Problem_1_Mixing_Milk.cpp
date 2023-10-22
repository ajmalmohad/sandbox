#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

int next(int bucket){
    return (bucket+1)%3;
}

void solve(){
    // freopen("mixmilk.in", "r", stdin);
    // freopen("mixmilk.out", "w", stdout);
    vector<ll> capacities(3);
    vector<ll> fills(3);
    for (int i = 0; i < 3; i++) {
        cin>>capacities[i];
        cin>>fills[i];
    }

    int bucket = 0;
    for (int i = 0; i < 100; i++) {
        if(fills[bucket] > (capacities[next(bucket)] - fills[next(bucket)])){
            fills[bucket] -= (capacities[next(bucket)] - fills[next(bucket)]);
            fills[next(bucket)] = capacities[next(bucket)];
        }else{
            fills[next(bucket)] += fills[bucket];
            fills[bucket] = 0;
        }
        bucket = next(bucket);
    }

    cout<<fills[0]<<"\n";
    cout<<fills[1]<<"\n";
    cout<<fills[2]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}