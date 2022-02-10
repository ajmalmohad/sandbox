#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

void solve(){
    ll levels;
    cin>>levels;
    levels++;
    vector<bool> record(levels, false);
    ll x;
    cin>>x;
    for (int i = 0; i < x; i++){
        ll temp;
        cin>>temp;
        record[temp] = true;
    }
    ll y;
    cin>>y;
    for (int i = 0; i < y; i++){
        ll temp;
        cin>>temp;
        record[temp] = true;
    }

    for (int i = 1; i < levels; i++)
    {
        if(record[i]==false){
            cout<<"Oh, my keyboard!\n";
            return;
        }
    }
    
    cout<<"I become the guy.\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
