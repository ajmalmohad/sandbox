#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> inputs(n);
    for (int i = 0; i < n; i++){
        cin>>inputs[i];
    }
    string s;
    cin>>s;
    unordered_map<int, char> record;
    for (int i = 0; i < s.size(); i++){
        if(record[inputs[i]]){
                if(record[inputs[i]]!=s[i]) {
                    cout<<"NO"<<'\n';
                    return;
                }
        }else{
            record[inputs[i]]=s[i];
        }
    }

    cout<<"YES"<<'\n';
}

int main(){
    int n;
    cin>>n;
    while (n--){
        solve();
    }
}