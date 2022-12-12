#include <iostream>

struct fecha {
   int dia, mes, anyo;

   fecha( ) {
      std::cout << "constructor por defecto\n";
      dia = -1, mes = -1, anyo = -1;
   }

   fecha(int d, int m, int a) {
      std::cout << "constructor con 3 ints\n";
      dia = d, mes = m, anyo = a;
   }

   fecha(const fecha& f) = delete; //borramos el constructor por copia, el compilador ya no lo hace
   /*
   fecha(const fecha& f) {
      std::cout << "constructor por copia\n";
      dia = f.dia, mes = f.mes, año = f.año;
   }
   */

   ~fecha( ) {
      std::cout << "destructor\n";
   }
};

int main( ) {
   fecha f;
   //std::cout << f.mes << "\n";

   fecha g(15, 11, 2022);
   //std::cout << g.mes << "\n";

   //fecha h = g; //NO jalara si borramos el constructor por copia:  fecha(const fecha& f) = delete;
   //std::cout << h.dia << "\n";
}
