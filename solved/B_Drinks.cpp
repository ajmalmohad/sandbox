#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    double n;
    cin>>n;
    double total = 0;
    for (int i = 0; i < n; i++){
        double drink;
        cin>>drink;
        total+=drink;
    }

    cout<<total/n<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
