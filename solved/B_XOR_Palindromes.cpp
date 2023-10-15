#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

int wrongPositions(string s){
    int count = 0;
    int start = 0;
    int end = s.size() - 1;
    while(start < end){
        if(s[start++] != s[end--]) {
            count++;
        }
    }
    return count;
}

// Based on wrong positions before
// and on length of string after

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    int wrong = wrongPositions(s);

    // Before correct
    for (int i = 0; i < wrong; i++) cout<<0;

    cout<<1;

    // After Correct
    for (int i = wrong+1; i <= n - wrong; i++){
        if(s.size()%2 == 1){
            cout<<1;
        }else{
            int rest = i - wrong;
            if(rest%2 == 0) cout<<1;
            else cout<<0;
        }
    }

    for (int i = 0; i < wrong; i++) cout<<0;
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    while(n--) solve();
}

