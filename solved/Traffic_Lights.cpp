#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    int n, m;
    cin>>n>>m;
    multiset<int> lengths;
    set<int> points;
    points.insert(0);
    points.insert(n);
    lengths.insert(n);

    for (int i = 0; i < m; i++){
        int temp, b;
        cin>>temp;

        auto point = points.upper_bound(temp);
        b = *point;
        point--;
        int a = *point;

        lengths.erase(lengths.find(b - a));
        lengths.insert(temp - a);
        lengths.insert(b - temp);
        
        points.insert(temp);
        cout<<*lengths.rbegin()<<" ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}