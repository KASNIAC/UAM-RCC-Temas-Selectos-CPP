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
   int r1, r2;
   std::thread h1([&]( ) {
      r1 = fibonacci(44);
   });
   std::thread h2([&]( ) {
      r2 = fibonacci(46);
   });
   h1.join( );
   h2.join( );
   std::cout << r1 << " " << r2 << "\n";
   std::cout << "adios :)\n";
}
