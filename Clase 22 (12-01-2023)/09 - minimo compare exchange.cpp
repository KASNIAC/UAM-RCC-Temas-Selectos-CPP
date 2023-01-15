#include <algorithm>
#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>

int main( ) {
   std::vector<int> arr;
   for (int i = 0; i < 200000000; ++i) {
      arr.push_back(rand( ));
   }

   auto t0 = std::chrono::high_resolution_clock::now( );
   std::future<int> h[4];
   std::atomic<int> minimo(std::numeric_limits<int>::max( ));
   for (int i = 0; i < 4; ++i) {
      h[i] = std::async(std::launch::async, [&, i]( ) {
         int ini = arr.size( ) / 4 * i, fin = ini + arr.size( ) / 4;
         for (int j = ini; j < fin; ++j) {
            for (;;) {
               int actual = minimo;
               if (actual <= arr[j]) {
                  break;
               }
               minimo.compare_exchange_strong(
                  actual, arr[j]
               );
            }
         }
      });
   }
   for (int i = 0; i < 4; ++i) {
      h[i].get( );
   }
   auto t1 = std::chrono::high_resolution_clock::now( );

   std::cout << minimo << "\n";
   std::cout << std::chrono::duration<double>(t1 - t0).count( ) << "\n";
}
