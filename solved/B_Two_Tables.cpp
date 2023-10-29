#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iomanip>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;
const int INF = int(1e9);

struct Rect{
    ll x1, y1, x2, y2;
    ll width() { return (x2 - x1); }
    ll height() { return (y2 - y1); }
};

ll yIntersect(pair<ll, ll> a, pair<ll, ll> b) { return max((ll)0, min(a.second, b.second) - max(a.first, b.first)); } // Find Y Intersect
ll xIntersect(pair<ll, ll> a, pair<ll, ll> b) { return max((ll)0, min(a.second, b.second) - max(a.first, b.first)); } // Find X Intersect

void solve(){
    Rect table;
    ll wRoom, hRoom, wNew, hNew, minm = INF;
    
    cin>>wRoom>>hRoom;
    cin>>table.x1>>table.y1>>table.x2>>table.y2;
    cin>>wNew>>hNew;

    if(wNew + table.width() <= wRoom){
        // minm = min(minm, xIntersect({table.x1, table.x2}, {0, wNew})); // When Left
        minm = min(minm, max((ll)0, wNew - table.x1)); // When Left
        // minm = min(minm, xIntersect({table.x1, table.x2}, {wRoom - wNew, wRoom})); // When Right
        minm = min(minm, max((ll)0, table.x2 - (wRoom - wNew))); // When Right
    }
    
    if(hNew + table.height() <= hRoom){
        // minm = min(minm, yIntersect({table.y1, table.y2}, {hRoom - hNew, hRoom})); // When Top
        minm = min(minm, max((ll)0, table.y2 - (hRoom - hNew))); // When Top
        // minm = min(minm, yIntersect({table.y1, table.y2}, {0, hNew})); // When Bottom
        minm = min(minm, max((ll)0, hNew - table.y1)); // When Bottom
    }
    
    if(minm == INF) cout<<"-1\n";
    else cout << double(minm) << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(9);
    ll n;
    cin>>n;
    while(n--) solve();
}