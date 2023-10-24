#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

struct Rect{
    int x1,y1,x2,y2;
    int area() { return (x2 - x1)*(y2 - y1); }
    int width() { return (x2 - x1); }
    int height() { return (y2 - y1); }
};

pair<int, int> intersect(Rect &a, Rect &b) {
    int xIntersect = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
    int yIntersect = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
    return {xIntersect, yIntersect};
}

void solve(){
    // freopen("billboard.in","r",stdin);
    // freopen("billboard.out","w",stdout);
    Rect lawn, feed;
    cin>>lawn.x1>>lawn.y1>>lawn.x2>>lawn.y2;
    cin>>feed.x1>>feed.y1>>feed.x2>>feed.y2;
    pair<int, int> intersects = intersect(lawn, feed);
    // Feed is in front

    // If lawn doesn't intersect with cow feed
    if(intersects.first == 0 || intersects.second == 0){
        cout<<lawn.area()<<"\n";
        return;
    }

    // If lawn intersect at corners (we need to cover whole lawn)
    if(intersects.first != lawn.width() && intersects.second != lawn.height()){
        cout<<lawn.area()<<"\n";
        return;
    }

    // If lawn is fully covered by cow feed
    if(intersects.first == lawn.width() && intersects.second == lawn.height()){
        cout<<0<<"\n";
        return;
    }

    // If lawn is in any 4 side covering a side part
    if( (lawn.y2 < feed.y2 && lawn.y1 <= feed.y1) ||
        (lawn.y1 > feed.y1 && lawn.y2 >= feed.y2) ||
        (lawn.x2 < feed.x2 && lawn.x1 <= feed.x1) || 
        (lawn.x1 > feed.x1 && lawn.x2 >= feed.x2)){
        cout<<lawn.area() - intersects.first*intersects.second;
    }else{
        // If lawn foes over the feed leaving 2 sides open above and below 
        // (or left and right)
        cout<<lawn.area();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}