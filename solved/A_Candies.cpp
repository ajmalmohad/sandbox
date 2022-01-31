#include <iostream>
#include <math.h>

void solve(){
    int n,k=2;
    std::cin>>n;
    
    int divisor,x,flag=1;

    while(flag){
        divisor = pow(2,k) - 1;
        int temp = n/divisor;
        if(n == temp*divisor){
            std::cout<<temp<<'\n';
            flag=0;
        }else{
            k++;
        }
    }
    
}

int main(){
    int t=1;
    std::cin>>t;
    while(t--){
        solve();
    }
}