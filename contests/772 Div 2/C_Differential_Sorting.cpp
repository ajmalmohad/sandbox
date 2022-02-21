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

    for (ll i = 0; i < n; i++){
        ll elem;
        cin>>elem;
        arr.push_back(elem);
    }

    vector<vector<ll>> output;
    for (ll i = 0; i < n-2; i++){
        if(arr[i+1] < arr[i]){
            ll sub = arr[i+1] - arr[i+2];
            if(sub > arr[i+1]){
                cout<<-1<<'\n';
                return;
            }
            arr[i] = sub;
            output.push_back({i+1, i+2, i+3});
        }
    }

    if(arr[n-1] < arr[n-2]){
        cout<<-1<<'\n';
        return;
    }


    cout<<output.size()<<'\n';
    for (auto x : output){
        for(auto y: x) cout<<y<<' ';
        cout<<'\n';
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}



// if(arr[i]>arr[i+1]){
//             if(i+2 < n){
//                 if(arr[i+1]-arr[i+2] < arr[i+1]){
//                     arr[i] = arr[i+1]-arr[i+2];
//                     output.push_back({i+1,i+2,i+3});
//                 }else{
//                     cout<<-1<<'\n';
//                 }
//             }else{
//                 if(arr[n-2] > arr[n-1]){
//                     cout<<-1<<'\n';
//                     return;
//                 }
//             }
//         }