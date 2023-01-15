//Este programa esta mal, pues solo calculamos el fibonacci, pero en ningun momento lo capturamos;
//El programa 05 soluciona este problema.
#include <iostream>
#include <thread>

int fibonacci(int n) {
   if (n <= 1) {
      return n;
   } else {
      return fibonacci(n - 1) + fibonacci(n - 2);
   }
}

int main( ) {
   std::cout << "hola :)\n";
   std::thread h1(fibonacci, 40);
   std::thread h2(fibonacci, 42);
   h1.join( );
   h2.join( );
   std::cout << "adios :)\n";
}
