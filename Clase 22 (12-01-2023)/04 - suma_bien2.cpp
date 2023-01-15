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
   std::future<void> h[4];
   long long sumas[4] = { }; //YA TENEMOS UNA VARIABLE PARA CADA HILO, Solucionando así el problema de atomic lento de 02 - suma_bien.cpp
   for (int i = 0; i < 4; ++i) {
      h[i] = std::async(std::launch::async, [&, i]( ) {
         int ini = arr.size( ) / 4 * i, fin = ini + arr.size( ) / 4;
         for (int j = ini; j < fin; ++j) {
            sumas[i] += arr[j]; //En realidad no esta escribiendo sobre el arreglo, lo promueve a registro y lo suma a final, false sharing
         }
      });
   }
   for (int i = 0; i < 4; ++i) {
      h[i].get( );
   }
   long long suma = sumas[0] + sumas[1] + sumas[2] + sumas[3];
   auto t1 = std::chrono::high_resolution_clock::now( );

   std::cout << suma << "\n";
   std::cout << std::chrono::duration<double>(t1 - t0).count( ) << "\n";
}
