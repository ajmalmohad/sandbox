#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

bool isPrime(ll n){
    for (ll i = 2; i <= sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    ll n=600851475143;
    ll largestPrime = 1;
    ll limit = sqrt(n);
    for (int i = 2; i <= limit; i++){
        if(n%i==0){
            if(n/i > largestPrime && isPrime(n/i)) largestPrime = n/i;
            if(i > largestPrime && isPrime(i)) largestPrime = i;
        }
    }
    cout<<largestPrime;
}
