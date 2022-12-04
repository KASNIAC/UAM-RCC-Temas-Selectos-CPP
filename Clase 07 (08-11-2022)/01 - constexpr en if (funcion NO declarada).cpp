#include <iostream>

void g(auto n){
    if constexpr(5 < 2){
        f(n);
    } else{
        std::cout<<"Hola";
    }
}

int main( ) {
   g(3);
}
