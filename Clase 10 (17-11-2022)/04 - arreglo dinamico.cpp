//Definiremos un tipo de dato para evitar andar haciendo new y delete a cada rato.
#include <iostream>

struct arreglo_dinamico {
   int* p;
   int tam;

   arreglo_dinamico( ) {
      p = nullptr;
      tam = 0;
      std::cout << "constructor sin parametros; la memoria qued� en " << p << "\n";
   }

   explicit arreglo_dinamico(int n) {
      p = new int[n];
      tam = n;
      std::cout << "constructor con parametros; la memoria qued� en " << p << "\n";
   }

   // constructor por copia
   arreglo_dinamico(const arreglo_dinamico& arr) {
      p = new int[arr.tam];
      tam = arr.tam;
      for (int i = 0; i < tam; ++i) {
         p[i] = arr.p[i];
      }
      std::cout << "constructor por copia; la memoria qued� en " << p << "\n";
   }

   //Sin un destructor no se liberar� la memoria
   ~arreglo_dinamico( ) {
      std::cout << "destructor; liberando " << p << "\n";
      delete[] p;
   }

   // asignaci�n por copia
   void operator=(const arreglo_dinamico& arr) {
      if (this == &arr) {    // no hay que hacer nada si nos
         return;             // queremos copiar a nosotros mismos  (a = a)
      }

      //ABAJO HAY UN PROBLEMA, PUES PRIMERO LIBERAMOS LA MEMORIA Y LUEGO LA APARTAMOS,
      // PERO SI NO LLEGAR� A HABER MEMORIA, NOS QUEDAR�AMOS COMO EL PERRO DE LAS DOS TORTAS
      // Este error se soluciona en la Clase 11

      delete[] p;    // liberamos la memoria que tal vez ten�amos
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
