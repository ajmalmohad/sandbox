#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    char x;
    set<char> record;
    while (cin>>x){
        if(x=='{' || x==',' || x==' ' || x=='}') continue;
        record.insert(x);
    }
    cout<<record.size()<<'\n'; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
