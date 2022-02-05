#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    ll width = 0;
    for (int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        if(temp>k){
            width+=2;
        }else{
            width+=1;
        }
    }

    cout<<width<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) solve();
    return 0;
}
