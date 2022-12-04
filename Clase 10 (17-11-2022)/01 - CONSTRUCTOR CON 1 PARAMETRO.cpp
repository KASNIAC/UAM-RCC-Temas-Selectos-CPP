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
};

void funcion(fecha v) {

}

int main( ) {
   fecha f;
   //std::cout << f.mes << "\n";

   fecha g(15, 11, 2022);
   //std::cout << g.mes << "\n";

   fecha h = g;
   //std::cout << h.dia << "\n";


   //fecha k = 2022; //NOTACION FEAAA, una fecha NO es un int (y eso es lo que parece). La deshabilita el explicit en el constructor de un int
   fecha x(2022);  //Notacion mejorcita.

   //Agregan el explicit en el constructor de un solo parámetro:
   // funcion(2023);
   funcion(fecha(2023));

}
