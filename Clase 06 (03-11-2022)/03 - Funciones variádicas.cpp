//1) Aplicando un operador binario:  (0 + ... + p)
/*
#include <iostream>

void f(auto... p) {
   std::cout << (0 + ... + p);
}

int main( ) {
   f(1, '@', 3.14, "hola");
}
*/

//2) Desempacando los prámetros en una llamada a función:
#include <iostream>

void imprime( ) {

}

void imprime(auto p0, auto... ps) {
   std::cout << p0;
   imprime(ps...);
}

//Yo la implememnte v:
auto lee(){

}
//Yo la implememnte v:
auto lee(auto& p0, auto&... ps){
    std::cin>>p0;
    lee(ps...);
}

int main( ) {
    int a, b,c;
    double x,y,z;
    lee(a,b,c,x,y,z);
    char e = ' ';
    imprime(a,e,b,e,c,e,x,e,y,e,z);

    //imprime(1, " ", 2, " ", 3.14, " adios");
}
