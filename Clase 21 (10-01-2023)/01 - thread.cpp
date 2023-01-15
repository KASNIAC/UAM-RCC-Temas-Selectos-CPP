// https://winlibs.com
// https://github.com/brechtsanders/winlibs_mingw/releases/download/12.2.0-15.0.6-10.0.0-ucrt-r3/winlibs-x86_64-posix-seh-gcc-12.2.0-mingw-w64ucrt-10.0.0-r3.zip
#include <iostream>
#include <thread>

void imprime( ) {
   for (int i = 0; i < 100; ++i) {
      std::cout << i << " ";
   }
}

int main( ) {
   std::cout << "hola :)\n";
   std::thread h1(imprime);
   std::thread h2(imprime);
   h1.join( );
   h2.join( );
   std::cout << "adios :)\n";
}
