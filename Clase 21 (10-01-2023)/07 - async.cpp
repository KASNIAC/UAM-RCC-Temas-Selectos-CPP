#include <chrono>
#include <future>
#include <iostream>

int fibonacci(int n) {
   if (n <= 1) {
      return n;
   } else {
      return fibonacci(n - 1) + fibonacci(n - 2);
   }
}

template<typename... T>
auto ejecuta_hilo(T&&... params) {
   return std::async(std::launch::async, std::forward<T>(params)...);
}

int main( ) {
   std::cout << "hola :)\n";

   auto t0 = std::chrono::high_resolution_clock::now( );

   auto h1 = ejecuta_hilo(fibonacci, 44); //Encapsulamos el async en una función, para evitar estar poniendo el std::launch::async (Tampoco es un gran drama estar poniendolo)

//El tipo de lo que devuelve std::async es un std::future<T>
   std::future<int> h2 = std::async(std::launch::async, fibonacci, 46); //Opción 1
// auto h2 = std::async(std::launch::async, fibonacci, 46); //Opcion 2, std::launch::async específica que sí queremos multihilo
                                                            //std::launch::deferred no lo queremos ejecutar de manera concurrente
                                                            //Sin este parámetro el compilador lo decide, por eso hicimos la funcion ejecuta_hilo
   int r1 = h1.get( );
   int r2 = h2.get( );
   auto t1 = std::chrono::high_resolution_clock::now( );

   std::cout << r1 << " " << r2 << "\n";
   std::cout << std::chrono::duration<double>(t1 - t0).count( ) << "\n";
   std::cout << "adios :)\n";
}
