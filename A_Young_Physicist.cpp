#include <iostream>

int main(){
    int n;
    std::cin>>n;
    int x=0,y=0,z=0;
    int xx,yy,zz;
    for (int i = 0; i < n; i++)
    {
        std::cin>>xx;
        std::cin>>yy;
        std::cin>>zz; 
        x+=xx;
        y+=yy;
        z+=zz;
    }
    if(x==0 && y==0 && z==0) std::cout<<"YES";
    else std::cout<<"NO";
}