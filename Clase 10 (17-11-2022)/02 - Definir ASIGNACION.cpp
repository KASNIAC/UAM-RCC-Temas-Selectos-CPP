
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

   //void operator=(const fecha& f) = delete; // Sí solo fuera void esto:  y = x = h = g = f; NO sería válido

   //fecha& operator=(const fecha& f) = delete;
   fecha& operator=(const fecha& f) {
      std::cout << "asignacion\n";
      dia = f.dia, mes = f.mes, anyo = f.anyo;
      return *this; //this debería de ser una referencia, pero es un apuntador por eso es necesario desreferenciarlo con el operador *
   }
};

int main( ) {
   fecha f;
   fecha g(15, 11, 2022);
   fecha h = g;
   fecha x(2022);

   fecha y;
   y = x = h = g = f;
}
