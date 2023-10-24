#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    string filename = "blist";
    freopen((filename+".in").c_str(),"r", stdin);
    freopen((filename+".out").c_str(),"w", stdout);
    int n, maxm = 0;
    cin>>n;
    int arr[1001] = {0};
    for (int i = 0; i < n; i++) {
        int si, ti, bi;
        cin>>si>>ti>>bi;
        for (int j = si; j <= ti; j++) {
            arr[j] += bi;
            maxm = max(maxm, arr[j]);
        }
    }
    cout<<maxm<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}