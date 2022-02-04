#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
void solve();


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) solve();
    return 0;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> arr;
    arr.reserve(n);

    for (int i = 0; i < n; i++){
        ll temp;
        cin>>temp;
        arr.push_back(temp);
    }

    int cycles = 0;
    int maxCount = 0;

    int ones = 0;
    int twos = 0;
    if(arr[0]==1) ones++;
    else twos++;

    for (int i = 1; i < n; i++){
        if(arr[i]==arr[i-1]){
            if(arr[i]==1) ones++;
            else twos++;
        }else{
            cycles++;
            if(arr[i]==1) ones++;
            else twos++;
            if(cycles>1){
                if(arr[i]==1) ones=1;
                else twos = 1;
                maxCount = max(maxCount, min(ones, twos)*2);
            }
        }
        maxCount = max(maxCount, min(ones, twos)*2);
    }

    cout<<maxCount<<'\n';
    
}