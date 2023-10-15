#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    int n, k, count = 0;
    cin>>n>>k;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin>>s[i];
    for (int i = 0; i < n; i++){
        count += s[i].size();
        if(count > k){
            cout<<"\n";
            cout<<s[i];
            count = s[i].size();
        }else{
            cout<<" "<<s[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}