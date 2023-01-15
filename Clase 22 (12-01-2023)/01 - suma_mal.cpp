//Sólo cambia el long long suma con respecto a 08 de la clase 21
#include <chrono>
#include <future>
#include <iostream>
#include <vector>
#include <stdlib.h>

int main( ) {
   std::vector<int> arr;
   for (int i = 0; i < 50000000; ++i) {
      arr.push_back(rand( ));
   }

   auto t0 = std::chrono::high_resolution_clock::now( );
   std::future<void> h[4];
   long long suma = 0;
   for (int i = 0; i < 4; ++i) {
      h[i] = std::async(std::launch::async, [&, i]( ) {
         int ini = 12500000 * i, fin = ini + 12500000;
         for (int j = ini; j < fin; ++j) {
            suma += arr[j];
         }
      });
   }
   for (int i = 0; i < 4; ++i) {
      h[i].get( );
   }
   auto t1 = std::chrono::high_resolution_clock::now( );

   std::cout << suma << "\n";
   std::cout << std::chrono::duration<double>(t1 - t0).count( ) << "\n";
}

