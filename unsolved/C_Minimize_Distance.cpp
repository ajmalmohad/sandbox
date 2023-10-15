#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n,k,num;
    cin>>n>>k;

    vector<long long> pos, neg;
    for (int i=0;i<n;i++) {
        cin>>num;
        if (num < 0) neg.push_back(num);
        else pos.push_back(num);
    }

    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());

    long long total=0;
    for (int i = 0; i < pos.size(); i+=k) total+=2*pos[i];
    for (int i = 0; i < neg.size(); i+=k) total+=2*abs(neg[i]);

    if(pos.size() && neg.size()){
        if(pos[0]>abs(neg[0])){
            total -= pos[0];
        }else{
            total -= abs(neg[0]);
        }
    }else if(pos.size()){
        total -= pos[0];
    }else{
        total -= abs(neg[0]);
    }

    cout<<total<<"\n";

}

int main(){
    int n;
    cin>>n;
    while(n--) solve();
}