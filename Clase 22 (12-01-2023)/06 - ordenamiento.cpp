
#include <algorithm>
#include <chrono>
#include <execution>
#include <iostream>
#include <vector>
#include <stdlib.h>

int main( ) {
   std::vector<int> arr;
   for (int i = 0; i < 200000000; ++i) {
      arr.push_back(rand( ));
   }

   auto t0 = std::chrono::high_resolution_clock::now( );
   std::sort(std::execution::par, arr.begin( ), arr.end( ));
   auto t1 = std::chrono::high_resolution_clock::now( );

   std::cout << std::chrono::duration<double>(t1 - t0).count( ) << "\n";
}

