#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

void solve();

int main(){
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}

void solve(){
    int n;
    cin>>n;
    int val;
    vector<bool> found(n+2,false);
    vector<int> extras;
    int foundCount = 0;
    for (int i = 0; i < n; i++){
        cin>>val;
        if(val<=n && found[val]==false) { found[val] = true; foundCount++; }
        else { extras.push_back(val); }
    }
    
    for (auto x : extras){
        for (int i = x; i > 0; i/=2){
            if(i <= n && !found[i]){
                found[i] = true;
                foundCount++;
                break;
            }
        }
    }

    if(foundCount == n) cout<<"YES\n";
    else cout<<"NO\n";
    
}