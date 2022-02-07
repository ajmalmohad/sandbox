#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll n,m;
    cin>>n>>m;
    ll pos=1;
    ll time = 0;
    for (int i = 0; i < m; i++){
        ll task;
        cin>>task;
        if(task == pos){
            continue;
        }else if(task > pos){
            time += task - pos;
            pos = task;
        }else if(task < pos){
            time += n - pos;
            pos = 0;
            time += task - pos;
            pos = task;
        }
    }
    
    cout<<time<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
