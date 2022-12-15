#include <iostream>

void f( ) {
   std::cout << "f\n";
}

void g( ) {
   std::cout << "g\n";
}

int main( ) {
   /*
   auto p = &f;
   (*p)( );
   p = &g;
   (*p)( );
   */

   auto p = f; //void(*p)( ) = f;
   p( );
   p = &g;
   p( );
}

