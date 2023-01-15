#include <iostream>
#include <thread>

void imprime( ) {
   for (int i = 0; i < 100000; ++i) {
      std::cout << i << " ";
   }
}

int main( ) {
   std::cout << "hola :)\n";
   std::jthread h1(imprime);
   std::jthread h2(imprime);
   std::cout << "adios :)\n";
}
