#include <iostream>

int main(){
    int n,x=0;
    char a,b;
    std::cin>>n;
    for (int i = 0; i < n; i++)
    {
        std::cin>>a;
        std::cin>>b;
        std::cin>>a;
        if(b=='+') x++;
        if(b=='-') x--;
    }
    std::cout<<x<<'\n';
}