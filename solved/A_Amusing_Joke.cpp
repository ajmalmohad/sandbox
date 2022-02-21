#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    string a,b,c;
    cin>>a>>b>>c;
    unordered_map<char, int> first;
    for (char letter : a) first[letter]++;
    for (char letter : b) first[letter]++;
    for (char letter : c) first[letter]--;
    for (auto letter : first){
        if(letter.second !=0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
