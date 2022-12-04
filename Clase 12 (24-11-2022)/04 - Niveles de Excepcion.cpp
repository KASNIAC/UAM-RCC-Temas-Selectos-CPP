#include <iostream>

struct arreglo_dinamico {
   int tam;
   int* p;

   arreglo_dinamico( ) {
      tam = 0, p = nullptr;
   }
   arreglo_dinamico(int t) {
      tam = t, p = new int[tam];
   }
   arreglo_dinamico(const arreglo_dinamico& a) {
      tam = a.tam, p = new int[tam];
      for (int i = 0; i < tam; ++i) {
         p[i] = a.p[i];
      }
   }
   ~arreglo_dinamico( ) {
      delete[] p;
   }

   void operator=(const arreglo_dinamico& a) {
      if (this != &a) {
         //PRIMERO PIDO LA MEMORIA PARA SOLUCIONAR EL PROBLEMA DE LA EXCEPCION!
         int* q = new int[a.tam];
         delete[] p;
         tam = a.tam, p = q;
         for (int i = 0; i < tam; ++i) {
            p[i] = a.p[i];
         }
      }
   }
};

int main( ) {
   arreglo_dinamico a(50);
   arreglo_dinamico b(3);
   try {
      b = a;
   } catch (const std::bad_alloc& ex) {
      // :) no sé que hacer
   }

   // imprimir b
}

