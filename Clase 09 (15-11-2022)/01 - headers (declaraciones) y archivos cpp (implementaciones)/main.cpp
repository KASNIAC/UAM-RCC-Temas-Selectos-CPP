
#include <iostream>
#include "biblioteca.h"
#include "biblioteca.h"

int main( ) {
   saluda( );
   std::cout << pi << "\n";

   //Sin haber imporatdo biblioteca.h y si declaro un fecha* f; no hay problema, porque es una dirección de memoria
    //Declarar un fecha f; sí es problema porque el compilador no sabe que es.

   fecha f = { 15, 11, 2022 };
   std::cout << obten_dia(f) << "\n";
   despide( );
}
