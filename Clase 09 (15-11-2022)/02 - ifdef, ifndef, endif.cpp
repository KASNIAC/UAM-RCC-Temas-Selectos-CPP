#include <iostream>
#define PRUEBAS

int main( ) {
   int n;
   std::cin >> n;
   #ifdef PRUEBAS
      std::cout << "Acabamos de leer " << n << "\n";
   #else
      std::cout << ":(";
   #endif
   std::cout << 2 * n;
}
/*

//-----------------

#ifndef BIBLIOTECA_H  // guarda de inclusión
   #define BIBLIOTECA_H
   #include <iostream>

   void saluda( );
   void despide( );
   extern double pi;
   struct fecha {
      int d, m, a;
   };
   int obten_dia(const fecha& f);
#endif

//-------------

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

//----------------

#include <iostream>
#include "biblioteca.h"
#include "biblioteca.h"

int main( ) {
   saluda( );
   std::cout << pi << "\n";
   fecha f = { 15, 11, 2022 };
   std::cout << obten_dia(f) << "\n";
   despide( );
}
*/
