#include<iostream>

auto g(int& n){

}

int main(){
        //NO se puede invocar con temporales
    //g(5);

        //NO se puede invocar con constantes
    //const int m;
    //g(m)

        //SI se puede con variables
    int n = 5;
    g(n);

        //COMPORTAMIENTO INDEFINIDO
    const int k = 5;
    //g(const_cast<int>(k)); //No jala si k nacio siendo una constante
}
