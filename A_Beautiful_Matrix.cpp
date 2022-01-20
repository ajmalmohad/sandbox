#include <iostream>

int main(){
    int temp;
    struct{
        int x;
        int y;
    } position;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cin>>temp;
            if(temp==1) position = {i,j};
        }
    }
    int dx,dy;
    dx = (position.x<2 || position.x>2) ? ((position.x<2) ? (2 - position.x) : -(2-position.x)) : 0;
    dy = (position.y<2 || position.y>2) ? ((position.y<2) ? (2 - position.y) : -(2-position.y)) : 0;
    std::cout<<dx+dy<<'\n';
}