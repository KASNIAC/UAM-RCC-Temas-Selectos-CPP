#include <array>
#include <iostream>
#include <vector>

template<typename T>
void imprime(const T& arr) {
   std::cout<<"Imprimiendo un T: ";
   for (int i = 0; i < arr.size( ); ++i) {
      std::cout << arr[i] << " ";
   }
   std::cout << "\n";
}

template<typename T, size_t N>
T suma(const std::array<T, N>& arr) {
   T res = 0;
   for (int i = 0; i < arr.size( ); ++i) {
      res += arr[i];
   }
   return res;
}

template<typename T>
T suma(const std::vector<T>& arr) {
   T res = 0;
   for (int i = 0; i < arr.size( ); ++i) {
      res += arr[i];
   }
   return res;
}

int main( ) {
   std::array<int, 5> a = { 1, 2, 3, 4, 5 };
   std::vector<int> v = { 1, 2, 3, 4, 5 };

   imprime(a);
   imprime(v);
   std::cout << suma(a) << "\n";
   std::cout << suma(v) << "\n";
}
