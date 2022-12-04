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
 //deshabilita la copia, prox clase
   //fecha(const fecha& f) = delete;

   ~fecha( ) {
      std::cout << "destructor\n";
   }
};

int main( ) {
   fecha f;
   std::cout << f.mes << "\n";

   fecha g(15, 11, 2022);
   //fecha g{15, 11, 2022}; //jala, pero no se recomienda
   std::cout << g.mes << "\n";


   fecha h = g;
   std::cout << h.dia << "\n";
   /*
   //Esta notacion no jala
    fecha h( );
    std::cout << h.mes << "\n";
   */
}
