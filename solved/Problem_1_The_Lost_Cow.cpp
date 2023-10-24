#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    int x, y, dist = 0, mult = 1, found = false;
    cin>>x>>y;

    if(x == y) {
        cout<<0<<"\n";
    }else{
        int temp;
        while(!found){
            temp = x + mult;
            if(y > x){
                if(temp >= y){ found = true; dist += abs(y - x); }
                else dist += abs(mult)*2;
            }else{
                if(temp <= y){ found = true; dist += abs(x - y); }
                else dist += abs(mult)*2;
            }
            mult*=-2;
        }
    }

    cout<<dist<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}