#include <iostream>
#include <thread>

void imprime(int ini, int fin) {
   for (int i = ini; i < fin; ++i) {
      std::cout << i << "\n";
   }
}

int main( ) {
   std::cout << "hola :)\n";
   std::thread h1(imprime, 5, 10000); //std::thread h1(imprime( 5, 10000) ); //estar�a mal, pues nosotros no queremos llamar a la funci�n
   std::thread h2(imprime, 9999, 999999);
   h1.join( );
   h2.join( );
   std::cout << "adios :)\n";
}
