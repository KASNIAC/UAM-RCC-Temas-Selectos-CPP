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
