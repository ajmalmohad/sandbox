#include <iostream>
using namespace std;

void solve();

int main(){
    int t=0;
    cin>>t;
    while(t--) solve();
}

void solve(){
    int i;
    cin>>i;
    long int maxprice = 0;
    while(i--){
        int store, people, price;
        cin>>store>>people>>price;
        maxprice = max((long int)(people/(store+1))*price,maxprice);
    }
    std::cout<<maxprice<<'\n';
}