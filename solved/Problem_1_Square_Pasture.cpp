#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    // freopen("square.in","r", stdin);
    // freopen("square.out","w", stdout);
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    int xSpan = max(x2,x4) - min(x1,x3);
    int ySpan = max(y2,y4) - min(y1,y3);
    int minSide = max(ySpan, xSpan);
    cout<<minSide*minSide<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}