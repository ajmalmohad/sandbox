#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    ll n, temp, mex = 0;
    cin>>n;
     
    for (int i = 0; i < n; i++){
        cin>>temp;
        if(temp == mex) mex++;
    }

    while(mex != -1 && mex != -2){
        cout<<mex<<"\n";
        cout.flush();
        cin>>mex;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    while(n--) solve();
}