//Definiremos un tipo de dato para evitar andando haciendo news y delete a cada rato.
#include <iostream>

struct arreglo_dinamico {
   int* p;
   int tam;

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

   //PROBLEMA!: constructor por copia
   arreglo_dinamico(const arreglo_dinamico& arr) {
      p = new int[arr.tam];
      tam = arr.tam;
      for (int i = 0; i < tam; ++i) {
         p[i] = arr.p[i];
      }
      std::cout << "constructor por copia; la memoria quedó en " << p << "\n";
   }

   //Sin un destructor, nuevamente no se liberará la memoria
   ~arreglo_dinamico( ) {
      std::cout << "destructor; liberando " << p << "\n";
      delete[] p;
   }

   //PROBLEMA!: constructor por copia
   void operator=(const arreglo_dinamico& arr) {
      if (this == &arr) {
         return;
      }

      delete[] p;
      p = new int[arr.tam];
      tam = arr.tam;
      for (int i = 0; i < tam; ++i) {
         p[i] = arr.p[i];
      }
   }
};

int main( ) {
   arreglo_dinamico arr(5);
   for (int i = 0; i < arr.tam; ++i) {
      arr.p[i] = 999;
   }

   arreglo_dinamico brr(7);
   brr = brr;
}
