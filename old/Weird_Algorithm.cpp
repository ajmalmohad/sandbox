#include<iostream>
using namespace std;
void solve();

int main()
{
    int t=1;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}

void solve(){
    long long n;
    cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n%2 == 0){
            n = n/2;
            cout<<n<<" ";
        }else{
            n = (n*3)+1;
            cout<<n<<" ";
        }
    }
}