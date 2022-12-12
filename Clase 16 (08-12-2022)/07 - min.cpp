#include <iostream>

// <algorithm> std::min
template<typename T> //Usar auto en lugar de template, haría que podamos comparar int vs string
const T& minimo(const T& a, const T& b) {
   return (a < b ? a : b);
}

int main( ) {
   int a = 2, b = 5;
   int c = minimo(a, b);
   std::cout << c << "\n";
   std::cout << minimo(5, 8LL) << "\n";
}
