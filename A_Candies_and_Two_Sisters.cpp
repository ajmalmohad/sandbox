#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    if(n<3) cout<<0<<"\n";
    else if(n%2==0) cout<<n/2 - 1<<"\n";
    else cout<<n/2<<"\n";
}

int main(){
    int n;
    cin>>n;
    while(n--) solve();
}