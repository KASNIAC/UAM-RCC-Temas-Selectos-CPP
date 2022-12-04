#include <iostream>
#include <utility>

struct arreglo_dinamico {
private:
   int tam;
   int* p;

public:
   arreglo_dinamico( ) {
      tam = 0;
      p = nullptr;
   }

   explicit arreglo_dinamico(int t) {
      tam = t;
      p = new int[t];
   }

   arreglo_dinamico(const arreglo_dinamico& a) {
      tam = a.tam;
      p = new int[a.tam];
      for (int i = 0; i < tam; ++i) {
         p[i] = a.p[i];
      }
   }

   arreglo_dinamico(arreglo_dinamico&& a) {
      tam = a.tam;
      p = a.p;
      a.tam = 0;
      a.p = nullptr;
   }

   ~arreglo_dinamico( ) {
      delete[] p;
   }

   void operator=(const arreglo_dinamico& a) {
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
      if (this != &a) {
         delete[] p;
         tam = a.tam;
         p = a.p;
         a.tam = 0;
         a.p = nullptr;
      }
   }

   //Esta funcion miembro promete no modificar nada de lo de el struct, ya con eso puedo usar la funcion imprimir.
   int size( ) const {
      return tam;
   }

   //Devuelve el elemento original al que le hará la copia con ese ampersand, ya jalará.
   int& operator[](int i) {
      return p[i];
   }

   //Sin este si podría modifica el arreglo_diamico en la funcion imprime, pues no prometí NO modificar a, sino no modificar p ni a, a[0] = 67657;
   const int& operator[](int i) const {
      return p[i];
   }
};

void imprime(const arreglo_dinamico& a) {
   //a[0] = 67657; // jalaría si no tuviera la sobrecarga de la funcion del operador []
   for (int i = 0; i < a.size( ); ++i) {
      std::cout << a[i] << " ";
   }
   std::cout << "\n";
}

int main( ) {
   arreglo_dinamico a(5);
   for (int i = 0; i < a.size( ); ++i) {
      a[i] = i * 2;
   }

   imprime(a);
}
