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
    for (int i = 0; i < n; i++){
        ll elem;
        cin>>elem;
        arr.push_back(elem);
    }

    ll count = 0;
    for (int i = 1; i < n-1; i++){
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            if(i<n-2 && arr[i+2]>=arr[i]) arr[i+1] = arr[i+2];
            else arr[i+1] = arr[i];
            count++;
        }
    }
    
    cout<<count<<'\n';
    for (auto elem : arr) cout<<elem<<' ';
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
