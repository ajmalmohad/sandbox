#include <iostream>

int main(){
    int price,money,want,total=0;
    std::cin>>price>>money>>want;
    for (int i = 1; i <= want; i++)
    {
        total += i*price;
    }
    total = total-money;
    if(total>0) std::cout<<total;
    else std::cout<<0;
}