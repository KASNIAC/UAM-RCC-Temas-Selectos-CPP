#include<iostream>

union prueba{
    char c;
    double d;
    int n;
};

int main(){
    prueba v;
    v.d = 3.14;
    std::cout<<v.c; //Imprimirá algo raro, el valor de v.d v:
}
