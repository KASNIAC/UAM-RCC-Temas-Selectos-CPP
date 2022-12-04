#include<iostream>

int f(int n){
    int r=0;
    std::cout<<n<<"\n";
    do{
        r+=1;
        n/=10;
        std::cout<<n<<"\n";
    }while(n>0);
    return r;
}
//cantidad de dígitos
int main(){
    int n=5;
    std::cout<<f(n);
    std::cout<<n;
}


