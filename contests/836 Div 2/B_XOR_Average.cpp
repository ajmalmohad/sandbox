#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n%2==1){
        for (int i = 0; i < n; i++) cout<<1<<" ";
    }else{
        for (int i = 0; i < n-2; i++) cout<<2<<" ";
        cout<<3<<" "<<1<<" ";
    }
    cout<<'\n';
}

int main(){
    int n;
    cin>>n;
    while(n--) solve();
}