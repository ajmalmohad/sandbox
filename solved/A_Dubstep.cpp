#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    string n;
    cin>>n;
    ll wupCount = 0;
    for (int i = 0; i < n.size(); i++){
        if(i<n.size()-2 && n[i]=='W' && n[i+1]=='U' && n[i+2]=='B'){
            i+=2;
            wupCount++;
            continue;
        }
        if(wupCount > 0 ){
            cout<<" ";
            wupCount = 0;
        }
        cout<<n[i];
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
