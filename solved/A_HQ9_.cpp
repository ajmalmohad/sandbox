#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

void solve(){
    string n;
    cin>>n;

    for (int i = 0; i < n.size(); i++){
        if(n[i] == 72 || n[i]== 81 || n[i] == 57){
            cout<<"YES\n";
            return;
        }
    }
    
    cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
