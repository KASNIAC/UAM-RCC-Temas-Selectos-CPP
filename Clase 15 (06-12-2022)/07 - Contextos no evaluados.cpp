#include <iostream>

int f( ) {
   std::cout << "hola";
   return 5;
}

// sizeof y decltype inician contextos no evaluados

int main( ) {
   std::cout << sizeof(f( )) << "\n";
   decltype(f( )) n = 5;
}
