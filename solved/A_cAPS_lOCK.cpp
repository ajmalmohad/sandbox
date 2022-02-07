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

    ll count = 0;
    int flag=0;
    for (int i = 0; i < n.size(); i++){
        if(n[i]>='A' && n[i]<='Z'){
            count++;
        }else if(i==0){
            flag=1;
        }
    }

    if(count==n.size() || (count==n.size()-1 && flag)){
        transform(n.begin(), n.end(), n.begin(), ::tolower);
    }

    if(count==n.size()-1 && flag){
        n[0] = toupper(n[0]);
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
