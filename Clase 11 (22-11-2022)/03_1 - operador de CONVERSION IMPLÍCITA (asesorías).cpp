#include <iostream>

struct ejemplo {
   operator int( ) {
      return 5;
   }
};

int main( ) {
   ejemplo e;
   int n = e;    // ok: se crea un temporal usando el operador de conversión implícita
                 // y ese temporal se usa para construir n
   std::cout << n << "\n";

   //int& r = e;   // error: el temporal no se puede usar para una referencia
}
