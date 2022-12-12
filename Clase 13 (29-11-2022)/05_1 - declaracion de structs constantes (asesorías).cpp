#include <iostream>

struct ejemplo {
   int a;

   void imprime( ) const {   // const aplica sobre this: permite que la función
      std::cout << a;        // miembro sea llamada sobre structs constantes
   }
};

int main( ) {
   const ejemplo e = { 5 };
   e.imprime( );
}
