#include <iostream>

int main(){
    std::string hello = "hello";
    std::string tried;
    std::cin>>tried;
    for (int i = 0; i <tried.size(); i++)
    {
        if(tried[i]==hello[0]){
            hello.erase(0,1);
        }
    }
    if(hello.size()>0) std::cout<<"NO";
    else std::cout<<"YES";
}