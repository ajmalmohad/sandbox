#include <iostream>
#include <unordered_set>
#include <string>

int main(){
    std::string a;
    std::string b;
    std::cin>>a;
    std::unordered_set<char> vowels;
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    vowels.insert('y');
    for (int i = 0; i < a.size(); i++)
    {
        if(vowels.find(std::tolower(a[i])) != vowels.end()){
            continue;
        }else{
            b += ".";
            b += std::tolower(a[i]);
        }
    }
    std::cout<<b<<'\n';
}