#include <iostream>

struct fecha {
   int dia, mes, anyo;

   fecha( ) {
      std::cout << "constructor por defecto\n";
      dia = -1, mes = -1, anyo = -1;
   }

   explicit fecha(int a) {
      std::cout << "constructor con 1 int\n";
      dia = 1, mes = 1, anyo = a;
   }

   fecha(int d, int m, int a) {
      std::cout << "constructor con 3 ints\n";
      dia = d, mes = m, anyo = a;
   }

   fecha(const fecha& f) {
      std::cout << "constructor por copia\n";
      dia = f.dia, mes = f.mes, anyo = f.anyo;
   }

   ~fecha( ) {
      std::cout << "destructor\n";
   }

   fecha& operator=(const fecha& f) {
      std::cout << "asignacion\n";
      dia = f.dia, mes = f.mes, anyo = f.anyo;
      return *this;
   }
};

int main( ) {
   //fecha arr[5]; //llama tanto a constructores como a destructores

   fecha* p = new fecha[5]; //Sólo llama a los constructores!
   p[2].dia = 17;
   delete[] p; //sin este no se destruyen los elementos

/*
   int n;
   std::cin >> n;

   fecha* p = new fecha[n]; //new T[n]; SÍ es válido en C++
   delete[] p;
*/
}
