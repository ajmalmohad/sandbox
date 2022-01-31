#include <iostream>

int main(){
    int n,k;
    std::cin>>n;
    std::cin>>k;
    while(k--){
        if(n%10!=0){
            n--;
        }else{
            n /=10;
        }
    }
    std::cout<<n;
}