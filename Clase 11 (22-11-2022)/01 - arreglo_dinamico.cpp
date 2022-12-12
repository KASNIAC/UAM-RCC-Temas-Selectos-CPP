// https://medium.com/@barryrevzin/value-categories-in-c-17-f56ae54bccbe
#include <iostream>
#include <utility>

struct arreglo_dinamico {
   int tam;
   int* p;

   arreglo_dinamico( ) {
      p = nullptr;
      tam = 0;
      std::cout << "constructor sin parametros; la memoria quedó en " << p << "\n";
   }

   explicit arreglo_dinamico(int n) {
      p = new int[n];
      tam = n;
      std::cout << "constructor con parametros; la memoria quedó en " << p << "\n";
   }

   // constructor por copia
   arreglo_dinamico(const arreglo_dinamico& arr) {
      p = new int[arr.tam];
      tam = arr.tam;
      for (int i = 0; i < tam; ++i) {
         p[i] = arr.p[i];
      }
      std::cout << "constructor por copia; la memoria quedó en " << p << "\n";
   }

    // constructor por movimiento
   arreglo_dinamico(arreglo_dinamico&& a) {
      std::cout << "constructor por movimiento\n";
      tam = a.tam;
      p = a.p;
      a.tam = 0;
      a.p = nullptr;
   }

   //Sin un destructor no se liberará la memoria
   ~arreglo_dinamico( ) {
      std::cout << "destructor; liberando " << p << "\n";
      delete[] p;
   }

   // asignación por copia
   void operator=(const arreglo_dinamico& arr) {
      if (this == &arr) {    // no hay que hacer nada si nos
         return;             // queremos copiar a nosotros mismos
      }

      //PROBLEMA DE LA Clase 10 SOLUCIONADO!
      int* q = new int[arr.tam];   // evitar quedarnos como el perro de las dos tortas: primero pedir memoria antes de liberar la que teníamos
      delete[] p;            // liberamos la memoria que tal vez teníamos
      p = q;
      tam = arr.tam;
      for (int i = 0; i < tam; ++i) {
         p[i] = arr.p[i];
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


   /*
   arreglo_dinamico arr(5);
   for (int i = 0; i < arr.tam; ++i) {
      arr.p[i] = 999;
   }

   arreglo_dinamico brr(7);
   brr = brr;

   */
}
