#include<iostream>
using namespace std;
typedef long long ll;

void solve();

int main(){
    int t=1;
    while(t--) solve();
    return 0;
}

void solve(){
    int t;
    cin>>t;
    string n;
    cin>>n;
    int acount = 0;
    int dcount = 0;
    for (int i = 0; i < t; i++){
        if(n[i]=='A') acount++;
        else dcount++;
    }
    
    if(acount>dcount) cout<<"Anton";
    else if(dcount>acount) cout<<"Danik";
    else cout<<"Friendship";
}