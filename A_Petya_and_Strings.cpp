#include <iostream>

int main(){
    std::string a;
    std::string b;
    int x = 0;
    std::cin>>a;
    std::cin>>b;
    int length = a.length();
    for (int i = 0; i < length; i++)
    {
        if(std::tolower(a[i])<std::tolower(b[i])){
            x = -1;
            break;
        }else if(std::tolower(a[i])>std::tolower(b[i])){
            x = 1;
            break;
        }
    }
    std::cout<<x<<'\n';
}