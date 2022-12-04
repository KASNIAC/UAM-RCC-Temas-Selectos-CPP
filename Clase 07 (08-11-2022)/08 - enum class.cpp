#include<iostream>

enum class prueba{
    xx,yy
};

int main(){
    //prueba p = xx; //MAL porque enum es class
    prueba p = prueba::xx;

    //std::cout<<p + 1<<"\n"; //MAL, necesaria una conversión explícita
    std::cout<<int(p) + 1<<"\n";
}
