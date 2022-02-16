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
    ll minIndex, minValue = LONG_MAX;
    ll maxIndex, maxValue = LONG_MIN;
    for (int i = 0; i < n; i++){
        int value;
        cin>>value;
        if(value<=minValue){
            minValue = value;
            minIndex = i;
        }
        if(value>maxValue){
            maxValue = value;
            maxIndex = i;
        }
    }
    if(minIndex < maxIndex) minIndex++;
    minIndex = (n - minIndex) - 1;
    cout<<minIndex+maxIndex;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
