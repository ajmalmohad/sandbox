#include <iostream>

int main(){
    int n,l,cap=0,temp=0;
    std::cin>>n;
    while(n--){
        std::cin>>l;
        temp -= l;
        std::cin>>l;
        temp += l;
        cap = std::max(cap,temp);
    }
    std::cout<<cap;
}