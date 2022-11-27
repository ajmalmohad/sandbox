#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    string s;
    cin>>s;
    string v = s;
    reverse(v.begin(),v.end());
    cout<<s<<v<<'\n';
}

int main(){
    int n;
    cin>>n;
    while(n--) solve();
}