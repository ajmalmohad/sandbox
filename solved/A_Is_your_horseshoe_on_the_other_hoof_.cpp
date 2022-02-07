#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;


void solve(){
    int count = 0;
    unordered_map<int,bool> record;
    for (int i = 0; i < 4; i++){
        int n;
        cin>>n;
        if(!record[n]){
            count++;
            record[n]=true;
        }
    }

    cout<<4 - count<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
