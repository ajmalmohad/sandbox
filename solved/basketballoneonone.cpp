#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    string s;
    cin>>s;
    int a = 0, b = 0, mode = 0;
    for (int i = 0; i < s.size(); i+=2){
        char scorer = s[i];
        int score = s[i+1] - '0';
        if(scorer == 'A') a+=score;
        else b+=score;

        if(a == 10 && b == 10) mode = 1;
        
        if(mode == 0){
            if(a >= 11){ cout<<"A\n"; break; }
            else if(b >= 11){ cout<<"B\n"; break; }
        }else{
            if(a - b >= 2){ cout<<"A\n"; break; }
            else if(b - a >= 2){ cout<<"B\n"; break; }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}