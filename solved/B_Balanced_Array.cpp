#include <iostream>

void solve(){
    int n;
    std::cin>>n;
    int arr[n];
    int leftsum=0, rightsum=0;
    for (int i = 0; i < n/2; i++)
    {
        arr[i] = (i+1)*2;
        leftsum += (i+1)*2;
    }
    int temp = 1;
    for (int i = n/2; i < n; i++)
    {
        arr[i] = temp;
        rightsum+= temp;
        temp+=2;
    }
    if((leftsum-rightsum)%2==0){
        std::cout<<"YES"<<'\n';
        if(leftsum<rightsum){
            arr[(n/2)-1] = arr[(n/2)-1]+(rightsum-leftsum);
        }else{
            arr[n-1] = arr[n-1]+(leftsum-rightsum);
        }
        for (int i = 0; i < n; i++)
        {
            std::cout<<arr[i]<<' ';
        }
        std::cout<<'\n';
    }else{
        std::cout<<"NO"<<'\n';
    }
}

int main(){
    int t=1;
    std::cin>>t;
    while(t--){
        solve();
    }
}