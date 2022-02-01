#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

void solve(){
    ll n,l;
    cin>>n>>l;
    ll prev=0;
    ll maxGap=0;
    ll maxDigit=0;
    ll minDigit=LONG_MAX;
    vector<ll> arr(n);

    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    sort(arr.begin(),arr.end());

    for (int i = 0; i < n; i++){
        maxGap = max(maxGap, arr[i]-prev);
        maxDigit = max(maxDigit, arr[i]);
        minDigit = min(minDigit, arr[i]);
        prev = arr[i];
    }

    maxGap = max(maxGap, (minDigit*2));
    maxGap = max(maxGap, (abs(l-maxDigit)*2));
    
    double ans = ((double)maxGap/2);

    cout<<fixed<<setprecision(10)<< ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}
