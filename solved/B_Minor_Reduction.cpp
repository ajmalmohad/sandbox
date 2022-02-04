#include<iostream>
#include<cmath>
#include <string>
using namespace std;
typedef long long ll;

void solve(){
    string number;
    cin>>number;

    for (int i = number.size() - 1; i > 0; i--){
        int d1 = number[i] - '0';
        int d2 = number[i-1] - '0';
        int sum = d1 + d2;

        if(sum >=10){ 
            string temp = to_string(sum);
            number[i-1] = temp[0];
            number[i] = temp[1];
            cout<<number<<'\n';
            return;
        }
    }

    int b1 = number[0] - '0';
    int b2 = number[1] - '0';
    string sum = to_string(b1 + b2);

    number = number.substr(1);
    number[0] = sum[0];

    cout<<number<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
