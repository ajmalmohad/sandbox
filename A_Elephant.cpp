#include <iostream>

int main(){
    int n;
    std::cin>>n;
    if (n%5 != 0 && n>5){
        std::cout<<(n/5 + 1);
    }else if(n%5 == 0){
        std::cout<<n/5;
    }else{
        std::cout<<1;
    }
}