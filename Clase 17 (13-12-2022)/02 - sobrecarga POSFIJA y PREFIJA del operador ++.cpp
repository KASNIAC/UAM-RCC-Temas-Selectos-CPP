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

   //void no permite el comportamiento ++it;
   // es necesario devolver una referencia, pero avanzarlo previamente
   iterador_entero& operator++( ) {
      ++valor;
      return *this;
   }

   //para el incremento posfijo es necesario agregar un int como parámetro
   // y usar la siguiente notacion:
   iterador_entero operator++(int) {
      auto copia = *this;
      ++valor;
      return copia;
   }

   bool operator==(const iterador_entero& otro) const {
      return valor == otro.valor;
   }
};

int main( ) {
   iterador_entero it(5);
   std::cout << *it << "\n";
   ++it;
   std::cout << *it << "\n";
   ++it;
   std::cout << *it << "\n";
   iterador_entero jt(6);
   std::cout << (it == jt) << "\n";
   std::cout << (it == ++jt) << "\n";
   jt++;








   /*
   for (int actual : rango_semi(0, 10)) {
      std::cout << actual << " ";
   }
   */
}
