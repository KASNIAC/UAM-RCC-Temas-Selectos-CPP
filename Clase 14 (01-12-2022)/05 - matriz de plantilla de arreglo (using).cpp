#include <iostream>

template<typename T, int N> // template<typename T, size_t N> //Opcion 1
struct arreglo {
   static_assert(N >= 0, "menso"); //Opcion 2 para evitar negativos
   T mem[N];

   T& operator[](int i) {
      return mem[i];
   }

   const T& operator[](int i) const {
      return mem[i];
   }

   void imprime( ) {
      for (int i = 0; i < N; ++i) {
         std::cout << mem[i] << " ";
      }
      std::cout << "\n";
   }
};

template<typename T, int N>
void imprime(const arreglo<T, N>& arr) {
   for (int i = 0; i < N; ++i) {
      std::cout << arr[i] << " ";
   }
   std::cout << "\n";
}

using entero = int;

template<typename T, int F, int C>
using matriz = arreglo<arreglo<T, C>, F>;

int main( ) {
   entero n;

   arreglo<int, 6> arr;
   arr[0] = 7; arr[1] = 3;
   arr[2] = 5; arr[3] = 8;
   arr[4] = 2; arr[5] = 0;
   arr.imprime( );
   imprime(arr);

   matriz<int, 5, 3> m;
   m[0][0] = 1;

   // arreglo<int, -3> x;  // ya no dará problemas debido al static_assert(N >= 0, "menso");
}
