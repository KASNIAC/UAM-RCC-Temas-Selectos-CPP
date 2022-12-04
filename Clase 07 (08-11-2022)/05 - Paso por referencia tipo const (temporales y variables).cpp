#include<iostream>

auto h(const int& n){

}

int main(){
    h(5);

    int n = 5;
    h(n);

    const int m = 5;
    h(m);
}
