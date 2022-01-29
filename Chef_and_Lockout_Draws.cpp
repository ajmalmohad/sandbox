#include<iostream>
using namespace std;
void solve();

int main()
{
    int t=1;
    cin>>t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b==c || a+c==b || b+c==a) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}