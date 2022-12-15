#include <algorithm>
#include <iostream>

struct iterador_entero {
   int valor;

   explicit iterador_entero(int v)
   : valor(v) {
   }

   int operator*( ) const {
      return valor;
   }

   iterador_entero& operator++( ) {
      ++valor;
      return *this;
   }

   iterador_entero operator++(int) {
      auto copia = *this;
      ++valor;
      return copia;
   }

   bool operator==(const iterador_entero& otro) const {
      return valor == otro.valor;
   }
};

struct rango_semi {
   iterador_entero ini;
   iterador_entero fin;

   rango_semi(int i, int f)
   : ini(i), fin(f) {
   }

   iterador_entero begin( ) const {
      return ini;
   }

   iterador_entero end( ) const {
      return fin;
   }
};

int main( ) {
   //rango_semi r(0,10);
   for (int actual : rango_semi(0, 10)) {
      std::cout << actual << " ";
   }
}
