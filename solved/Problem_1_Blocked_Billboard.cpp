#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

struct Rect {
    int x1, y1, x2, y2;
    int area() { return (x2-x1)*(y2-y1); }
};

int intersect(Rect p, Rect q) {
    int xOverlap = min(p.x2, q.x2) - max(p.x1, q.x1);
    int yOverlap = min(p.y2, q.y2) - max(p.y1, q.y1);
    if(xOverlap > 0 && yOverlap > 0) return xOverlap*yOverlap;
    else return 0; 
}

void solve(){
    Rect a, b, c;
    cin>>a.x1>>a.y1>>a.x2>>a.y2;
    cin>>b.x1>>b.y1>>b.x2>>b.y2;
    cin>>c.x1>>c.y1>>c.x2>>c.y2;

    cout<<a.area()+b.area()-intersect(a,c)-intersect(b,c);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}