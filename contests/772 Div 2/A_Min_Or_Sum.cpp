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

    vector<ll> arr;
    arr.reserve(n);

    ll sum=0;

    for (ll i = 0; i < n; i++){
        ll elem;
        cin>>elem;
        sum+=elem;
        arr.push_back(elem);
    }

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if((arr[i] | arr[j]) >= arr[i]+arr[j]){
                continue;
            }else{
                ll num = arr[i] | arr[j];
                sum -= (arr[i]+arr[j]);
                sum += num;
                arr[i] = 0;
                arr[j] = num;
            }
        }
    }
    
    cout<<sum<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
