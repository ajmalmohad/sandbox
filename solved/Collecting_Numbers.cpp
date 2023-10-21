#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    ll n, num, count = 0;
    cin>>n;
    vector<bool> collected(n+1, false);
    for (int i = 0; i < n; i++) {
        cin>>num;
        if(num == 1){
            count++;
            collected[num] = true;
        }else{
            if(collected[num-1]){
                collected[num] = true;
            }else{
                count++;
                collected[num] = true;
            }
        }
    }

    cout<<count<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}