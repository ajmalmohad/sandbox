#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    int temp;
    int evenPos=0, oddPos=0;
    int odds=0, evens=0;
    for (int i = 0; i < n; i++){
        cin>>temp;
        if(temp%2==0) { evenPos = i+1; evens++; }
        else { oddPos = i+1; odds++; }
    }

    if(evens>odds) cout<<oddPos<<'\n';
    else cout<<evenPos<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}
