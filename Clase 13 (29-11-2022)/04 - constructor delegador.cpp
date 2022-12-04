#include <iostream>

class vector {
   int* mem;
   int tam, cap;

public:
   vector( )        // constructor delegador
   : vector(0) {
   }

   vector(int n)
   : vector(n, 0) {
   }

   vector(int n, int v)
   : mem(new int[n]), tam(n), cap(n) {  //CONSTRUCCION
      //mem = new int[n], tam = n, cap = n; // ASIGNACION
      for (int i = 0; i < n; ++i) {
         mem[i] = v;
      }
   }

   //...
};

int main( ) {
   vector v1;        // vacío
   vector v2(5);     // cinco ints que valen 0
   vector v3(5, 7);  // cinco ints que valen 7
}
