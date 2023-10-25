#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    int n, temp;
    cin>>n;
    vector<int> towers;
    for (int i = 0; i < n; i++) {
        cin>>temp;
        int idx = (int)(upper_bound(towers.begin(), towers.end(), temp) - towers.begin());
        if(idx != (int)towers.size()){
            towers[idx] = temp;
        }else{
            towers.push_back(temp);
        }
    }

    cout<<towers.size()<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}