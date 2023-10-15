#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, c, d;
    cin>>a>>b>>c>>d;
    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }

    if(c > d){
        int temp = c;
        c = d;
        d = temp;
    }

    if((a<=c && b<=c) || (a>=d && b>=d)){
        cout<<b - a<<"\n";
    }else{
        int ans = b - a;
        
        int teleport = abs(c - a) + abs(d - b);
        if(teleport < ans){
            cout<<teleport<<"\n";
        }else{
            cout<<ans<<"\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}