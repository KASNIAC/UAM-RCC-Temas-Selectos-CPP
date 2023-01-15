#include <chrono>
#include <iostream>
#include <vector>
#include <stdlib.h>

int main( ) {
   std::vector<int> arr;
   for (int i = 0; i < 50000000; ++i) {
      arr.push_back(rand( ));
   }

   auto t0 = std::chrono::high_resolution_clock::now( );
   long long suma = 0;
   for (int j = 0; j < arr.size( ); ++j) {
      suma += arr[j];
   }
   auto t1 = std::chrono::high_resolution_clock::now( );

   std::cout << suma << "\n";
   std::cout << std::chrono::duration<double>(t1 - t0).count( ) << "\n";
}

