#include <iostream>
#include <thread>

void imprime(int ini, int fin) {
   for (int i = ini; i < fin; ++i) {
      std::cout << i << "\n";
   }
}

int main( ) {
   std::cout << "hola :)\n";
   std::thread h1(imprime, 5, 10000); //std::thread h1(imprime( 5, 10000) ); //estaría mal, pues nosotros no queremos llamar a la función
   std::thread h2(imprime, 9999, 999999);
   h1.join( );
   h2.join( );
   std::cout << "adios :)\n";
}
