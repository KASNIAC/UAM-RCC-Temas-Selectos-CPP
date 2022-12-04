#include <array>
#include <iostream>

void f(std::array<int, 5> a) {
   a[0] = 8;
}

void g(std::array<int, 5>& a) {
   a[0] = 777;
}

std::array<int, 5> h( ) {
   std::array<int, 5> b = { { 4, 4, 4, 4, 4 } };
   return b;
}

template<typename T, size_t F, size_t C>
using matrix = std::array<std::array<T, C>, F>;

/*
//En caso de querer matrices multidimensionales
template<typename T, size_t... DIMS>
using matrix = std::array<std::array<AQUI QUE VA?>;
*/

int main( ) {
   std::array<int, 5> a = { { 1, 2, 3, 4, 5 } };

   f(a);
   std::cout << a[0] << "\n";

   g(a);
   std::cout << a[0] << "\n";

   std::array<int, 5> b = h( );
   std::cout << b[0] << "\n";


   //Declaración de una matriz:
   std::array<std::array<int, 5>, 2> matriz;
   matrix<int, 2, 5> mat;
}











