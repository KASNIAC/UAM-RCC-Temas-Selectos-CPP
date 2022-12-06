#include <array>
#include <iostream>
#include <vector>

template<typename T>
void imprime(const T& arr) {
   for (int i = 0; i < arr.size( ); ++i) {
      std::cout << arr[i] << " ";
   }
   std::cout << "\n";
}

template<typename T>
auto suma(const T& arr) {
   typename T::value_type res = 0;
 //std::remove_cvref_t<decltype(arr[0])> res = 0;
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

   std::vector<double> f = { 3.14, 2.78, 1.23, 9.99 };
   imprime(f);
   std::cout << suma(f) << "\n";

   std::array<char, 8>::value_type c = '@';
}
