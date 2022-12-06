#include <iostream> 
 
template<typename T, int N> 
struct arreglo { 
   static_assert(N > 0); 
   T mem[N]; 
 
   T& operator[](int i) { 
      return mem[i]; 
   } 
 
   const T& operator[](int i) const { 
      return mem[i]; 
   } 
}; 
 
template<typename T, int F, int C> 
using matriz = arreglo<arreglo<T, C>, F>; 
 
int main( ) { 
   arreglo<int, 5> a; 
   a[2] = 7; 
   std::cout << a[2] << "\n"; 
 
   matriz<int, 2, 3> m; 
   m[1][2] = 7; 
   std::cout << m[1][2] << "\n"; 
}
