#include <chrono>
#include <iostream>
#include <thread>

int fibonacci(int n) {
   if (n <= 1) {
      return n;
   } else {
      return fibonacci(n - 1) + fibonacci(n - 2);
   }
}

int main( ) {
   std::cout << "hola :)\n";

   auto t0 = std::chrono::high_resolution_clock::now( );
   int r1, r2;
   std::thread h1([&]( ) {
      r1 = fibonacci(44);
   });
   std::thread h2([&]( ) {
      r2 = fibonacci(46);
   });
   h1.join( );
   h2.join( );
   auto t1 = std::chrono::high_resolution_clock::now( );

   std::cout << r1 << " " << r2 << "\n";
   std::cout << std::chrono::duration<double>(t1 - t0).count( ) << "\n";
   std::cout << "adios :)\n";
}
