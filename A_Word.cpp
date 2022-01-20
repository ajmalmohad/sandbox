#include <iostream>

int main(){
    std::string a;
    std::cin>>a;
    int u=0,l=0;
    for (int i = 0; i < a.size(); i++)
    {
        if(std::isupper(a[i])) u++;
        else l++;
    }
    if(u>l){
        for (int i = 0; i < a.size(); i++)
        {
            a[i] = std::toupper(a[i]);
        }
    }else{
        for (int i = 0; i < a.size(); i++)
        {
            a[i] = std::tolower(a[i]);
        }
    }
    std::cout<<a<<'\n';
}