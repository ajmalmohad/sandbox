#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;

unordered_map<string, bool> names;
unordered_map<string, int> counts;

void solve(){
    string n;
    cin>>n;
    if(names[n]){
        counts[n]++;
        cout<<n<<counts[n]<<'\n';
    }else{
        names[n] = true;
        cout<<"OK\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
