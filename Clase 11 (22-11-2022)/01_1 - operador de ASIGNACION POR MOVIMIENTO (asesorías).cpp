#include <iostream>

struct s {
   s( ) {
      std::cout << "constructor por defecto\n";
   }

   s(const s&) {
      std::cout << "constructor por copia\n";
   }

   s(s&&) {
      std::cout << "constructor por movimiento\n";
   }

   void operator=(const s&) {
      std::cout << "asignacion por copia\n";
   }

   void operator=(s&&) {
      std::cout << "asignacion por movimiento\n";
   }
};

void intercambia(s& a, s& b) {
   s c = std::move(a);
   a = std::move(b);
   b = std::move(c);
}

int main( ) {
   s a, b;
   intercambia(a, b);
}
