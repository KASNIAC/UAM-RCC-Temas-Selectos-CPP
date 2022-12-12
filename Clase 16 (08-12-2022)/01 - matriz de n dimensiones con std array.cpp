#include <array>
#include <iostream>

template<typename T, size_t... N>
struct matriz_impl;

template<typename T, size_t N>
struct matriz_impl<T, N> {
   using tipo = std::array<T, N>;
};

template<typename T, size_t N1, size_t... NS>
struct matriz_impl<T, N1, NS...> {
   using tipo = std::array<typename matriz_impl<T, NS...>::tipo, N1 >;
};

template<typename T, size_t... N>
using matriz = typename matriz_impl<T, N...>::tipo;

int main( ) {
   matriz<int, 2> m1;
   matriz<int, 2, 3> m2;
   matriz<int, 2, 3, 4> m3;

   std::cout << sizeof(m1) << "\n";
   std::cout << sizeof(m2) << "\n";
   std::cout << sizeof(m3) << "\n";

   m3[0][1][2] = 7;
   std::cout << m3[0][1][2] << "\n";
   matriz<int, 2, 3, 4> m4 = m3;
   std::cout << m4[0][1][2] << "\n";
}
