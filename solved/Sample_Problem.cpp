#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(int t){
    ll n,m;
    cin>>n>>m;
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
        total+=temp;
    }
    cout<<"Case #"<<t<<": "<<total%m<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    for(int i=1; i<=t; i++) solve(i);
    return 0;
}
