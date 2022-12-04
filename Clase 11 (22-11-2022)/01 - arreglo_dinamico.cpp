// https://medium.com/@barryrevzin/value-categories-in-c-17-f56ae54bccbe
#include <iostream>
#include <utility>

struct arreglo_dinamico {
   int tam;
   int* p;

   arreglo_dinamico( ) {
      std::cout << "constructor\n";
      tam = 0;
      p = nullptr;
   }

   explicit arreglo_dinamico(int t) {
      std::cout << "constructor\n";
      tam = t;
      p = new int[t];
   }

   arreglo_dinamico(const arreglo_dinamico& a) {
      std::cout << "constructor por copia\n";
      tam = a.tam;
      p = new int[a.tam];
      for (int i = 0; i < tam; ++i) {
         p[i] = a.p[i];
      }
   }

   arreglo_dinamico(arreglo_dinamico&& a) {
      std::cout << "constructor por movimiento\n";
      tam = a.tam;
      p = a.p;
      a.tam = 0;
      a.p = nullptr;
   }

   ~arreglo_dinamico( ) {
      std::cout << "destructor\n";
      delete[] p;
   }

   void operator=(const arreglo_dinamico& a) {
      std::cout << "asignacion por copia\n";
      if (this != &a) {
         delete[] p;
         tam = a.tam;
         p = new int[a.tam];
         for (int i = 0; i < tam; ++i) {
            p[i] = a.p[i];
         }
      }
   }

   void operator=(arreglo_dinamico&& a) {
      std::cout << "asignacion por movimiento\n";
      if (this != &a) {
         delete[] p;
         tam = a.tam;
         p = a.p;
         a.tam = 0;
         a.p = nullptr;
      }
   }
};

arreglo_dinamico f( ) {
   arreglo_dinamico torre[3] = {
      arreglo_dinamico(5),
      arreglo_dinamico(8),
      arreglo_dinamico(3)
   };
   //return torre[1]; //segurá usando el constuctor por copia pues sigue siendo un lvalue

   return std::move(torre[1]); //le digo que sea un rvalue, ahora si se cae con el apuntador y evito andar haciendo copias a lo idiota
}

int main( ) {
   arreglo_dinamico a = f( );
   std::cout << "-----\n";
}
