#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <vector>
#include <stdlib.h>

int main( ) {
   std::vector<int> arr;
   for (int i = 0; i < 200000000; ++i) {
      arr.push_back(rand( ));
   }

   auto t0 = std::chrono::high_resolution_clock::now( );
   std::future<long long> h[4];
   for (int i = 0; i < 4; ++i) {
      h[i] = std::async(std::launch::async, [&, i]( ) {
         int ini = arr.size( ) / 4 * i, fin = ini + arr.size( ) / 4;
         long long suma_local = 0;
         for (int j = ini; j < fin; ++j) {
            suma_local += arr[j];
         }
         return suma_local;
      });
   }
   long long suma = 0;
   for (int i = 0; i < 4; ++i) {
      suma += h[i].get( );
   }
   auto t1 = std::chrono::high_resolution_clock::now( );

   std::cout << suma << "\n";
   std::cout << std::chrono::duration<double>(t1 - t0).count( ) << "\n";
}
