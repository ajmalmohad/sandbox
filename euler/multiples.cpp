#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll n,count=0;
    for (int i = 1; i < 1000; i++){
        if(i%3 == 0 || i%5 == 0){
            count+= i;
        }
    }
    cout<<count<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
