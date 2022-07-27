#include <iostream>
using namespace std;

int hasher(string str, int capacity){
    int value = 0;
    for (int i = 0; i < str.size(); i++) value += (int)str[i];
    return value % capacity;
}

int main(){
    int capacity = 10;
    int hash_table[capacity];
}