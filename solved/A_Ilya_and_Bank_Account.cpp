#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    string n;
    cin>>n;
    if(n[0] == '-') {
        int a = n[n.size()-1] - '0';
        int b = n[n.size()-2] - '0';
        if(a>b){
            n.erase(n.begin()+n.size()-1);
        }else{
            n[n.size()-2] = n[n.size()-1];
            n.erase(n.begin()+n.size()-1);
        }
        if(n.size()==2 && n[1]=='0') n.erase(n.begin());
    }
    cout<<n<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
