#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll n,m;
    cin>>n>>m;

    ll swaps = 0;

    ll mySum = 0;
    vector<ll> myteam;
    myteam.reserve(n);

    ll otherSum = 0;
    vector<ll> otherteam;
    otherteam.reserve(m);

    ll temp;
    for (int i = 0; i < n; i++){
        cin>>temp;
        myteam.push_back(temp);
        mySum+=temp;
    }

    for (int i = 0; i < m; i++){
        cin>>temp;
        otherteam.push_back(temp);
        otherSum+=temp;
    }


    if(mySum > otherSum){
        cout<<swaps<<'\n';
        return;
    }

    sort(myteam.begin(),myteam.end());
    sort(otherteam.begin(),otherteam.end(), greater<int>());

    for (int i = 0; i < min(m,n); i++){
        if(otherteam[i]>myteam[i]){
            ll sum = otherteam[i] - myteam[i];
            mySum += sum;
            otherSum -= sum;
            swaps++;
        }else break;
        if(mySum > otherSum) break;
    }  

    if(mySum<=otherSum){
        cout<<"-1\n";
        return;
    }
    cout<<swaps<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
