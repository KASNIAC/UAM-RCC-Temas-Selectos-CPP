#include <iostream>

void saluda( ) {
   std::cout << "hola\n";
}

void despide( ) {
   std::cout << "adios\n";
}

double pi = 3.1416;

struct fecha {
   int d, m, a;
};

int obten_dia(const fecha& f) {
   return f.d;
}
